# Intel-mainline (public)
# git://github.com/intel/mainline-tracking.git;protocol=https;nobranch=1;name=machine
KERNEL_SRC_URI:pn-linux-intel-ese-lts-5.4 = "git://${TOPDIR}/../managed/linux-intel-ese-lts-5.4;name=machine;branch=HEAD;nobranch=1;protocol=file;usehead=1"
SRCREV_machine:pn-linux-intel-ese-lts-5.4 = "${AUTOREV}"
LINUX_VERSION:pn-linux-intel-ese-lts-5.4  = "5.4+"
KERNEL_CONFIG_URI:pn-linux-intel-ese-lts-5.4 = "git://${TOPDIR}/../managed/yocto-kernel-cache-5.4;type=kmeta;name=meta;protocol=file;destsuffix=${KMETA};branch=HEAD;nobranch=1;usehead=1"
SRCREV_meta:pn-linux-intel-ese-lts-5.4 = "${AUTOREV}"

# networkproxy
KERNEL_WRAP:pn-linux-intel-ese-lts-5.4-networkproxy = "linux-intel-ese-lts-5.4"
KERNEL_SRC_URI:pn-linux-intel-ese-lts-5.4-networkproxy = "${KERNEL_SRC_URI:pn-linux-intel-ese-lts-5.4}"
SRCREV_machine:pn-linux-intel-ese-lts-5.4-networkproxy = "${AUTOREV}"
LINUX_VERSION:pn-linux-intel-ese-lts-5.4-networkproxy = "${LINUX_VERSION:pn-linux-intel-ese-lts-5.4}"
KERNEL_CONFIG_URI:pn-linux-intel-ese-lts-5.4-networkproxy = "${KERNEL_CONFIG_URI:pn-linux-intel-ese-lts-5.4}"
SRCREV_meta:pn-linux-intel-ese-lts-5.4-networkproxy = "${SRCREV_meta:pn-linux-intel-ese-lts-5.4}"

# Intel-RT (public)
KERNEL_SRC_URI:pn-linux-intel-ese-lts-rt-5.4 = "git://${TOPDIR}/../managed/linux-intel-ese-lts-rt-5.4;name=machine;branch=HEAD;nobranch=1;protocol=file;usehead=1"
SRCREV_machine:pn-linux-intel-ese-lts-rt-5.4 = "${AUTOREV}"
LINUX_VERSION:pn-linux-intel-ese-lts-rt-5.4  = "5.4+"
KERNEL_CONFIG_URI:pn-linux-intel-ese-lts-rt-5.4 = "${KERNEL_CONFIG_URI:pn-linux-intel-ese-lts-5.4}"
SRCREV_meta:pn-linux-intel-ese-lts-rt-5.4 = "${SRCREV_meta:pn-linux-intel-ese-lts-5.4}"
