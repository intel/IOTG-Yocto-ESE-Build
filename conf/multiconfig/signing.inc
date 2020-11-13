### Set this to secure-boot-certificates to use randomly generated keys, preset keys will not be used
# the same randomly generated keys will be used until secure-boot-certificates yocto recipe is cleaned up
# use "bitbake [multiconfing prefix]secure-boot-certificates -c cleansstate" to clean up
# pregenerated certs/keys will only be used if set to "secure-boot-certificates-pregenerated"
# set to "secure-boot-certificates" to use randomly generated keys
PREFERRED_PROVIDER_virtual/secure-boot-certificates = "secure-boot-certificates-pregenerated"
# these lines configure openssl key generation options
SECURE_BOOT_CERT_GEN_ALGO = "rsa"
SECURE_BOOT_CERT_GEN_LENGTH = "4096"
SECURE_BOOT_CERT_GEN_HASH = "sha384"
SECURE_BOOT_CERT_GEN_SUBJECT = "/CN=BSP Signing Key/"

### Pregenerated secure boot Certs/Keys
# we want to use sha256 variants, set to "sha384" to use newer keys
PREGENERATED_SIGNING_KEY_TYPE = "sha256"
PREGENERATED_SIGNING_KEY_DIR  = "${TOPDIR}/cert/${PREGENERATED_SIGNING_KEY_TYPE}"
PREGENERATED_SIGNING_KEY_DB_KEY = "DB.key"
PREGENERATED_SIGNING_KEY_DB_CRT = "DB.crt"
PREGENERATED_SIGNING_KEY_MOK_KEY = "yocto.key"
PREGENERATED_SIGNING_KEY_MOK_CRT = "yocto.crt"
PREGENERATED_SIGNING_KEY_SHIM_KEY = "shim.key"
PREGENERATED_SIGNING_KEY_SHIM_CRT = "shim.crt"
### End Pregenerated Keys

# There are multiple keys for slimboot
PREGENERATED_SIGNING_KEY_SLIMBOOT_KEY_SHA256 = "${TOPDIR}/cert/TestSigningPrivateKey.pem"
PREGENERATED_SIGNING_KEY_SLIMBOOT_KEY_SHA384 = "${TOPDIR}/cert/TestSigningPrivateKey_RSA3072.pem"

# where to symlink "sbl_os" to by default, may be sbl_os_3k
#DEFAULT_secure-boot-certificates-slimboot = "sbl_os_2k"
# sbl_os_2k keys
#PREFERRED_PROVIDER_virtual/secure-boot-certificates-slimboot-2048 = "secure-boot-certificates-slimboot-2048"
# sbl_os_3k keys
#PREFERRED_PROVIDER_virtual/secure-boot-certificates-slimboot-3072 = "secure-boot-certificates-slimboot-3072"
