# this file makes the LTS kernel the default boot option

PREFERRED_PROVIDER_virtual/kernel = "linux-intel-ese-lts-5.4"
# this variable key is resolved too late and has to be written manually
# KERNEL_PACKAGE_NAME_pn-${PREFERRED_PROVIDER_virtual/kernel} = "kernel"
KERNEL_PACKAGE_NAME_pn-linux-intel-ese-lts-5.4 = "kernel"

# Secondary kernel for RT support bootable through grub
IMAGE_INSTALL_append = " linux-intel-ese-lts-rt-5.4-kernel-modules"
WKS_EXTRA_KERNELS_append = " linux-intel-ese-lts-rt-5.4-kernel"
IMAGE_INSTALL_append = " linux-intel-ese-lts-rt-5.4-kernel-image-signed linux-intel-ese-lts-rt-5.4-kernel-image-sblimage linux-intel-ese-lts-rt-5.4-kernel-image-sblimage-sha256 linux-intel-ese-lts-rt-5.4-kernel-image-sblimage-sha384"
IMAGE_INSTALL_append_pn-core-image-sato-sdk = " linux-intel-ese-lts-rt-5.4-kernel-dev"
KERNEL_PROVIDERS_append = " linux-intel-ese-lts-rt-5.4"
