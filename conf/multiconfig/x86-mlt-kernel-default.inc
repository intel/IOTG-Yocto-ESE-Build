# this file makes the MLT kernel the default boot option

PREFERRED_PROVIDER_virtual/kernel = "linux-intel-ese-mlt"
# this variable key is resolved too late and has to be written manually
# KERNEL_PACKAGE_NAME_pn-${PREFERRED_PROVIDER_virtual/kernel} = "kernel"
KERNEL_PACKAGE_NAME_pn-linux-intel-ese-mlt = "kernel"

KERNEL_PROVIDERS[5.9] += "${PREFERRED_PROVIDER_virtual/kernel}"

# Secondary LTS kernel support bootable through grub
IMAGE_INSTALL_append = " linux-intel-ese-lts-5.4-kernel-modules"
WKS_EXTRA_KERNELS_append = " linux-intel-ese-lts-5.4-kernel"
IMAGE_INSTALL_append = " linux-intel-ese-lts-5.4-kernel-image linux-intel-ese-lts-5.4-kernel-image-sblimage-sha256 linux-intel-ese-lts-5.4-kernel-image-sblimage-sha384"
IMAGE_INSTALL_append_pn-core-image-sato-sdk = " linux-intel-ese-lts-5.4-kernel-dev"
KERNEL_PROVIDERS[5.4] += "linux-intel-ese-lts-5.4"

# Secondary kernel for RT support bootable through grub
IMAGE_INSTALL_append = " linux-intel-ese-lts-rt-5.4-kernel-modules"
WKS_EXTRA_KERNELS_append = " linux-intel-ese-lts-rt-5.4-kernel"
IMAGE_INSTALL_append = " linux-intel-ese-lts-rt-5.4-kernel-image linux-intel-ese-lts-rt-5.4-kernel-image-sblimage-sha256 linux-intel-ese-lts-rt-5.4-kernel-image-sblimage-sha384"
IMAGE_INSTALL_append_pn-core-image-sato-sdk = " linux-intel-ese-lts-rt-5.4-kernel-dev"
KERNEL_PROVIDERS[5.4] += " linux-intel-ese-lts-rt-5.4"

# DPDK (i210) stack for TCCSDK
# BBCLASSEXTEND method of extending the out-of-tree modules manually is rather clumsy but
# this is a special case because the same recipe also installs userspace binaries and
# kernel modules, making the non-module files duplicated and clashing upon image do_rootfs.
# We use a bbappend file to split the packages and prevent duplication.
#
# It is preferable to use KERNEL_PROVIDERS[tag] and KERNEL_PROVIDERS_EXTRA_MODULES[tag]
# see packagegroup-kernel-oot.bb in ese-bsp for more details.
BBCLASSEXTEND_append_pn-dpdk = " kernel-oot-module:linux-intel-ese-lts-5.4 kernel-oot-module:linux-intel-ese-lts-rt-5.4"
IMAGE_INSTALL_append = " linux-intel-ese-lts-5.4-dpdk linux-intel-ese-lts-rt-5.4-dpdk"
KERNEL_PROVIDERS_EXTRA_MODULES[5.4] += "dpdk-modules"
