[Defines]
  DEC_SPECIFICATION = 2.7
  PACKAGE_NAME      = TucanaPlatformPkg
  PACKAGE_GUID      = 12345678-abcd-efgh-ijkl-9876543210ab
  PACKAGE_VERSION   = 1.0

[Sources]
  TucanaPlatformPkg.inf

[Packages]
  MdePkg/MdePkg.dec
  ...

[LibraryClasses]
  UefiBootServicesTableLib
  UefiRuntimeServicesTableLib
  BaseLib

[Protocols]
  gEfiConsoleControlProtocolGuid
  ...

[Ppis]
  gEfiPeiReadOnlyVariable2PpiGuid
  ...

[Guids]
  gTucanaPlatformPkgTokenSpaceGuid
  ...