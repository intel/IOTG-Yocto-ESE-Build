require ./x86-common.inc
# default kernel
##### IMPORTANT: WHEN MODIFYING THIS FILE, tmp-glic/cache may get outdated, delete it before running bitbake again
# you may also need to run cleansstate on any images you built earlier

MACHINE = "intel-corei7-64"

SSTATE_DIR = "${TOPDIR}/sstate-cache-${BB_CURRENT_MC}"
TMPDIR="${TOPDIR}/tmp-${BB_CURRENT_MC}"

include ${SELECTABLE_KERNEL_DEFAULT}
KERNEL_PROVIDERS_append = " ${PREFERRED_PROVIDER_virtual/kernel}"

# To add support for signed image installation to non-removable media,
# user needs the parted tool and custom scripts
#IMAGE_INSTALL_append = " parted secboot-script"
# To boot up signed image from boot medium with boot and rootfs located
# at different partitions, DISK_SIGNATURE_UUID is required.
#DISK_SIGNATURE_UUID = "f1f27ee1-1898-496e-bcb8-18188fc08072"
DISK_SIGNATURE_UUID = ""

#### size configuration
IMAGE_OVERHEAD_FACTOR = "1.0"
IMAGE_FSTYPES = "wic wic.bmap"
WKS_ROOT_SIZE_MB ??= "12288"
WKS_DATA_SIZE_MB ??= "12288"
WKS_BOOT_SIZE_MB ??= "128"
WKS_SWAP_SIZE_MB ??= "4096"
WKS_ROOT_FS = "ext4"
WKS_ROOT_TYPE ?= "EBD0A0A2-B9E5-4433-87C0-68B6B72699C7"
WKS_ROOT_TYPE_x86 = "44479540-F297-41B2-9AF7-D131D5F0458A"
WKS_ROOT_TYPE_x86-64 = "4F68BCE3-E8CD-4DB1-96E7-FBCAF984B709"
WKS_ROOT_TYPE_arm = "69DAD710-2CE4-4E3C-B16C-21A1D49ABED3"
WKS_ROOT_TYPE_aarch64 = "B921B045-1DF0-41C3-AF44-4C6F280D3FAE"
WKS_FILE = "mender-io.wks.in"
WKS_FILE_DEPENDS += "sbsigntool-native grub-efi grub-native cpio-native virtual/secure-boot-certificates shim"

#### Mender settings
MENDER_FEATURES_DISABLE_append = " mender-image-uefi mender-systemd"
INHERIT += "mender-full"
# missing files?
PACKAGECONFIG_append_pn-mender = " modules"
# MENDER_ARTIFACT_NAME needs to be defined globally
MENDER_ARTIFACT_NAME = "Release-${DATETIME}"
MENDER_ARTIFACT_NAME[vardepsexclude] = "DATETIME"
MENDER_IMAGE_ROOTFS_MAXSIZE_DEFAULT = ""
MENDER_STORAGE_TOTAL_SIZE_MB = "32768"
IMAGE_ROOTFS_SIZE = "${@int(round(${WKS_ROOT_SIZE_MB} * 1024 - (${IMAGE_ROOTFS_EXTRA_SPACE})))}"
IMAGE_ROOTFS_MAXSIZE = "${@int(round(${WKS_ROOT_SIZE_MB} * 1024))}"
ROOTFS_POSTPROCESS_COMMAND_remove = "mender_update_fstab_file;"
MENDER_BOOT_PART_MOUNT_LOCATION = "/boot/efi"
SYSTEMD_AUTO_ENABLE_pn-mender = "disable"
ARTIFACTIMG_FSTYPE = "${WKS_ROOT_FS}"
IMAGE_ROOTFS_EXCLUDE_PATH_append = " etc/"
# Mender relabeling post-update script
IMAGE_INSTALL_append = " mender-relabel mender-reconf"
# Mender helper init
INITRAMFS_IMAGE_NAME = "mender-initramfs"
INITRAMFS_IMAGE_RECIPE = "mc:${BB_CURRENT_MC}:x86-musl:${INITRAMFS_IMAGE_NAME}"
INITRAMFS_IMAGE_PATH = "${TOPDIR}/tmp-x86-musl-musl/deploy/images/${MACHINE}/${INITRAMFS_IMAGE_NAME}-${MACHINE}.cpio"
# Mender boot hints
APPEND += "mender.efi=PARTLABEL=efi mender.primary=PARTLABEL=primary mender.secondary=PARTLABEL=secondary mender.data=PARTLABEL=data mender.swap=PARTLABEL=swap resume=PARTLABEL=swap"
# Mender image: move /etc to /data/persistent/etc
IMGCLASSES_append = " mender-persistent"

# internal testing stub
include ${TOPDIR}/conf/internal/sdk.conf
include ${TOPDIR}/conf/internal/kernel.conf
