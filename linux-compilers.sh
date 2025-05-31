#!/bin/bash

set -e

echo "🔧 Welcome to the Linux Kernel Configuration and Compilation Script!"

# Prompt for Kernel Version
read -p "📌 Enter the Linux kernel version you want to install (e.g., 6.9.1): " KERNEL_VERSION
KERNEL_TAR="linux-${KERNEL_VERSION}.tar.xz"
KERNEL_DIR="linux-${KERNEL_VERSION}"

# Download Kernel if not already present
if [ -f "$KERNEL_TAR" ]; then
    echo "✅ Kernel tarball $KERNEL_TAR already exists. Skipping download."
else
    echo "⬇️ Downloading Kernel version $KERNEL_VERSION..."
    wget https://cdn.kernel.org/pub/linux/kernel/v${KERNEL_VERSION:0:1}.x/$KERNEL_TAR
fi

# Extract if not already extracted
if [ -d "$KERNEL_DIR" ]; then
    echo "📁 Kernel directory $KERNEL_DIR already exists. Skipping extraction."
else
    echo "📦 Extracting the kernel tarball..."
    unxz -v $KERNEL_TAR
    tar xvf ${KERNEL_TAR%.xz}
fi

cd $KERNEL_DIR

# Check for signature verification
SIGNATURE_FILE="linux-${KERNEL_VERSION}.tar.sign"
if [ ! -f "$SIGNATURE_FILE" ]; then
    echo "🔏 Downloading signature file..."
    wget https://cdn.kernel.org/pub/linux/kernel/v${KERNEL_VERSION:0:1}.x/$SIGNATURE_FILE
fi

echo "🔐 Verifying signature..."
if ! gpg --verify $SIGNATURE_FILE; then
    echo "⚠️ GPG verification failed! You may need to import the correct key."
    read -p "Do you want to continue anyway? (y/n): " CONT
    [[ "$CONT" != "y" ]] && exit 1
fi

# Copy existing config
echo "⚙️ Copying current kernel config..."
cp -v /boot/config-$(uname -r) .config

# Ask to run menuconfig
read -p "🛠️ Do you want to customize the kernel configuration with 'menuconfig'? (y/n): " CUSTOM
if [[ "$CUSTOM" == "y" ]]; then
    make menuconfig
fi

# Install requirements and run setup script
echo "📦 Installing required tools and compiler..."
bash <(curl -s https://raw.githubusercontent.com/the-asherbrook-06/linux/main/linux-compilers.sh)

# Compile kernel
echo "🏗️ Compiling the kernel... this may take a while ⏳"
make -j$(nproc)

echo "📦 Installing modules..."
sudo make modules_install

echo "💾 Installing the kernel..."
sudo make install

echo "🔧 Updating GRUB..."
sudo update-grub

# Ask before rebooting
read -p "🔁 Do you want to reboot now to use the new kernel? (y/n): " REBOOT
if [[ "$REBOOT" == "y" ]]; then
    echo "🔄 Rebooting..."
    sudo reboot
else
    echo "✅ Done! You can reboot later to use the new kernel."
fi
