#
# This file is your local configuration file and is where all local user settings
# are placed. The comments in this file give some guide to the options a new user
# to the system might want to change but pretty much any configuration option can
# be set in this file. More adventurous users can look at local.conf.extended
# which contains other examples of configuration which can be placed in this file
# but new users likely won't need any of them initially.
#
# Lines starting with the '#' character are commented out and in some cases the
# default values are provided as comments to show people example syntax. Enabling
# the option is a question of removing the # character and making any change to the
# variable as required.

# Security package
IMAGE_INSTALL_append = " libseccomp apparmor jhi smack"
DISTRO_FEATURES_append = " apparmor"

# Apparmor & seccomp support
APPEND += "apparmor=1 security=apparmor mem_sleep_default=deep"
DEPENDS_append_pn-systemd = " apparmor"
PACKAGECONFIG_append_pn-systemd = " gnutls seccomp lz4"
PACKAGECONFIG_append_pn-gnutls = " seccomp"
BBCLASSEXTEND_pn-libseccomp = "native nativesdk"

# early preinit-env handler
IMAGE_INSTALL_append = " preinit-env"
APPEND_append = " init=/sbin/preinit-env"

# Network package
IMAGE_INSTALL_append = " mosquitto"

PREFERRED_VERSION_systemd-bootchart = "233%"

# Runtime environment export setting for x11
IMAGE_INSTALL_append = " xserver-nodm-config"

BSP_SUBTYPE = "x86"

MACHINE_FEATURES_remove = "pcbios"

DISTRO_FEATURES_append = " x11 wayland vulkan"
CORE_IMAGE_EXTRA_INSTALL += "wayland weston"
DISTRO_FEATURES_NATIVE_append = " x11"
DISTRO_FEATURES_NATIVESDK_append = " x11"

# Set preferred version for media
PREFERRED_VERSION_gstreamer1.0 = "1.17%"
PREFERRED_VERSION_gstreamer1.0-plugins-base = "${PREFERRED_VERSION_gstreamer1.0}"
PREFERRED_VERSION_gstreamer1.0-plugins-bad = "${PREFERRED_VERSION_gstreamer1.0}"
PREFERRED_VERSION_gstreamer1.0-plugins-good = "${PREFERRED_VERSION_gstreamer1.0}"
PREFERRED_VERSION_gstreamer1.0-vaapi = "${PREFERRED_VERSION_gstreamer1.0}"
IMAGE_INSTALL_append = " gstreamer1.0-libav"
PREFERRED_VERSION_intel-media-driver = "20.1%"
PREFERRED_VERSION_gmmlib = "20%"
PREFERRED_VERSION_gmmlib-native = "${PREFERRED_VERSION_gmmlib}"
PREFERRED_VERSION_intel-mediasdk = "20.1%"
DISTRO_FEATURES_append = " msdk"
IMAGE_INSTALL_append = " intel-media-driver"
IMAGE_INSTALL_append = "${@bb.utils.contains("DISTRO_FEATURES","msdk", " intel-mediasdk", "", d)}"
PACKAGECONFIG_append_pn-gstreamer1.0-libav = " libav"
IMAGE_INSTALL_append = " vulkan-loader"

# mesa iris driver
PACKAGECONFIG_append_pn-mesa_class-target = " gallium gallium-llvm"
MESA_FORCE_DRIVER = "iris"
PREFERRED_PROVIDER_virtual/mesa-native = "${PREFERRED_PROVIDER_virtual/mesa}-native"
PACKAGECONFIG_append_pn-mesa-native_class-native = " gles"
# clang/llvm native build is broken, mesa doing the insane by using native llvm to find out about host llvm
# make sure some PACKAGECONFIG is at least common in meta-clang clang/llvm
PACKAGECONFIG_append_pn-clang = " rtti eh  shared-libs"
PACKAGECONFIG_append_pn-clang-native = " rtti eh shared-libs"
LLVMVERSION = "9.0.0"
PREFERRED_VERSION_llvm = "${LLVMVERSION}"
PREFERRED_VERSION_llvm-native = "${LLVMVERSION}"
PREFERRED_VERSION_nativesdk-llvm = "${LLVMVERSION}"

# Add fwupdate packages
IMAGE_INSTALL_append = " fwupdate fwupdate-boot"

# Remove ltp to reduce image size
PACKAGE_EXCLUDE = "ltp"
RDEPENDS_packagegroup-core-tools-testapps_remove = " ltp"

# Required additional host tools
HOSTTOOLS += "git-lfs"

# Enable ocl-icd and neo for elkhart-lake
IMAGE_INSTALL_append = " ocl-icd intel-compute-runtime"

# Enable ptp daemons
IMAGE_INSTALL_append = " gptp linuxptp net-snmp"

# Enable cups
IMAGE_INSTALL_append = " cups"

# Enable freeglut for elkhart-lake
IMAGE_INSTALL_append = " freeglut"

#################
# ESE PACKAGES
#################

# ESE specific packagegroups
IMAGE_INSTALL_append = " packagegroup-ese-coretools"
IMAGE_INSTALL_append = " packagegroup-ese-graphics"
IMAGE_INSTALL_append = " packagegroup-ese-graphics-2d"
IMAGE_INSTALL_append = " packagegroup-ese-graphics-display"
IMAGE_INSTALL_append = " packagegroup-ese-graphics-media"
IMAGE_INSTALL_append = " packagegroup-ese-graphics-tools"
IMAGE_INSTALL_append = " packagegroup-ese-multimedia"
IMAGE_INSTALL_append = " packagegroup-ese-wireless"
IMAGE_INSTALL_append = " packagegroup-core-x11-extended"

# Weston/Wayland
IMAGE_INSTALL_append = " wayland weston"

# Contents from meta-tpm2 and configuration
IMAGE_INSTALL_append = " packagegroup-ese-tpm2"
EXTRA_OECONF_append_pn-tpm2-tss = " --with-tctidefaultmodule=libtss2-tcti-tabrmd.so"

# Add multimedia components
DISTRO_FEATURES_append = " pulseaudio"

# linux-firmware
IMAGE_INSTALL_append = " linux-firmware"

# Add wifi/bluetooth components, uncomment the following line to use out of tree iwlwifi and disable the kernel wifi drivers
DISTRO_FEATURES_append = " backport-iwlwifi"
KERNEL_PROVIDERS_EXTRA_MODULES_append = "${@bb.utils.contains("DISTRO_FEATURES","backport-iwlwifi", " backport-iwlwifi", "", d)}"

# Bluetooth management
IMAGE_INSTALL_append = " bluez5-noinst-tools bluez5-testtools"

# Enable TPM drivers
MACHINE_FEATURES_append = " tpm"

# Enable LMS
IMAGE_INSTALL_append = " lms"

# Logging support
IMAGE_INSTALL_append = " logrotate"

# Remove unnecessary packages installed in sato image
IMAGE_INSTALL_remove = " packagegroup-core-x11-sato-games kernel-devsrc"

# Remove unnecessary image features added in sato-sdk image
IMAGE_FEATURES_remove = "eclipse-debug tools-profile"

# X11-related
IMAGE_INSTALL_append = " xinput"

# Production-type image optional
#INHERIT += "extrausers"
#EXTRA_USERS_PARAMS = "${@bb.utils.contains("IMAGE_FEATURES","allow-empty-password", "", "usermod -P 1876*18 root;", d)}"

# prefer bleeding edge iproute2
PREFERRED_VERSION_iproute2 = "git%"

# Install TSN tool
IMAGE_INSTALL_append = " ethtool iproute2 iproute2-tc iperf3 tcpdump linuxptp stress-ng"

# Qemu virtualization support
DISTRO_FEATURES_append = " virtualization"
IMAGE_INSTALL_append = " qemu ovmf-edk2"

# Using icewm instead of matchbox
IMAGE_INSTALL_append = " icewm"
RDEPENDS_packagegroup-core-x11-base_remove_pn-packagegroup-core-x11-base = "matchbox-terminal matchbox-wm mini-x-session"
RDEPENDS_packagegroup-core-x11-sato-base_remove_pn-packagegroup-core-x11-sato = " \
    matchbox-desktop \
    matchbox-session-sato \
    matchbox-keyboard \
    matchbox-keyboard-applet \
    matchbox-keyboard-im \
    matchbox-config-gtk \
    xcursor-transparent-theme \
    adwaita-icon-theme \
    settings-daemon \
    shutdown-desktop \
"
RDEPENDS_packagegroup-core-x11-sato_remove_pn-packagegroup-core-x11-sato = "packagegroup-core-x11-sato-games packagegroup-core-x11-sato-apps"

#################
# ESE PACKAGES
#################

# use openssh instead of dropbear
IMAGE_FEATURES_remove = "ssh-server-dropbear"
IMAGE_FEATURES_append = " ssh-server-openssh"

# Workaround for the bug to generate nativesdk
TOOLCHAIN_HOST_TASK_append = " nativesdk-cmake-dev"

# Workaround kernel 4.20 no longer having oldnoconfig
KERNEL_CONFIG_COMMAND = "oe_runmake_call -C ${S} O=${B} olddefconfig"

#skip apparmor ptest
PTEST_ENABLED_pn-apparmor = ""
SYSTEMD_AUTO_ENABLE_pn-apparmor = "enable"

# Enable secureboot for elkhart-lake
require ./signing.inc
SECURITY_NO_FORTIFY_CFLAGS = "-fstack-protector-strong -pie -fpie -Wformat -Wformat-security"
SECUREBOOT = "true"

# Grub-efi provider
EFI_PROVIDER = "grub-efi"
SHIM_LOADER_IMAGE = "grubx64.efi"

# enable signed kernel image for secure boot
# uncomment to bundle Intel CPU microcode update with kernel
#KERNEL_CLASSES_append = " kernel-microcode"
# uncomment to bundle Intel i915 firmware into the kernel
#KERNEL_CLASSES_append = " kernel-i915-fw"
# enable slimboot
# bundle initrd for secure boot
KERNEL_CLASSES_append = " kernel-sign kernel-sblimage kernel-initrd"

# default kernel (virtual provider set in multiconfig with internal overrides)
IMAGE_INSTALL_append = " kernel-image-signed kernel-modules"

# convenience packge to pull in any other out-of-tree kernel drivers
# See KERNEL_PROVIDERS_EXTRA_MODULES variable
IMAGE_INSTALL_append = " packagegroup-kernel-oot"

# Not actually needed, handled elsewhere through wic plugins
MACHINE_ESSENTIAL_EXTRA_RDEPENDS_remove = "kernel-image"
BAD_RECOMMENDATIONS_append = " grub-efi-bootimg virtual/grub-bootconf"
RDEPENDS_grub-efi_remove_class-target = "virtual/grub-bootconf"

# autoload modules
KERNEL_MODULE_AUTOLOAD_append = " configfs uhid"

# use consolekit2
PREFERRED_RPROVIDER_consolekit = "consolekit2"

# subregion capsule generation tool
IMAGE_INSTALL_append = " fbu"

# Additional serial consoles
SERIAL_CONSOLES_append = " 115200;ttyS4 115200;ttyS5"
APPEND_append = " console=ttyS4,115200n8 console=ttyS5,115200n8 i915.force_probe=* i915.enable_guc=2" 

# OS-release info
IMAGE_INSTALL_append = " os-release"

# IASImage settings for Slimboot
IMAGE_INSTALL_append = " kernel-image-sblimage"

## Enable Smack support ##
#OVERRIDES .= ":smack"
DISTRO_FEATURES_append = " smack"

# Remove initscripts from the image altogether.
VIRTUAL-RUNTIME_initscripts = ""

# Smack utilities is useful.
#CORE_IMAGE_EXTRA_INSTALL += " systemd-analyze coreutils smack-userspace"

# Exclude conflicting smack recipe
#BBMASK = "meta-security/recipes-mac/smack"

## End of Smack support ##

# SGX
KERNEL_PROVIDERS_EXTRA_MODULES_append = " isgx"
IMAGE_INSTALL_append = " sgx isgx-blacklist"
RECOMMENDS_sgx_remove = "kernel-modules-isgx"

###################
# OpenVINO PACKAGES
###################

# Enable clDNN only when needed, as this will pull in additional compile-time
# and runtime dependencies for Intel Graphics Compute Runtime for OpenCL
PACKAGECONFIG_append_pn-dldt-inference-engine = " opencl"

# Enable building inference engine python API.
PACKAGECONFIG_append_pn-dldt-inference-engine = " python3"

# This adds inference engine related libraries to the target image
IMAGE_INSTALL_append = " dldt-inference-engine"

# This adds inference engine samples to the target image
IMAGE_INSTALL_append = " dldt-inference-engine-samples"

# Include inference engine python API package to the target image.
# This is required for running e2e_oss test cases
IMAGE_INSTALL_append = " dldt-inference-engine-python3"

# Enable MYRIAD plugin
IMAGE_INSTALL_append = " dldt-inference-engine-vpu-firmware"

# Include model optimizer to the target image.
# This is required for running e2e_oss test cases
IMAGE_INSTALL_append = " dldt-model-optimizer"

# python3 packages needed by the inference engine python test script to transform the input image to expected format
IMAGE_INSTALL_append = " python3-opencv python3-numpy"

###################
# OpenVINO PACKAGES
###################

# This file is for internal use, but should not affect external builds
include ${TOPDIR}/conf/internal/internal.inc

########## clang/llvm size problems
BAD_RECOMMENDATIONS_append = " clang-staticdev"

# Adding recipes for platform specific changes
IMAGE_INSTALL_append = " audio-hda-load"

# usb mouse wakeup and SATA PM
IMAGE_INSTALL_append = " udev-usbpower udev-satapower"
