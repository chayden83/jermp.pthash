cmake_minimum_required(VERSION 3.5...4.0)

project(vault.pthash
  DESCRIPTION "State-of-the art library for generating minimal perfect hashes"
  LANGUAGES   CXX
  VERSION     0.1.0
)

enable_testing()

include(FetchContent)
include(GNUInstallDirs)

include(cmake/vault-configure.cmake)

add_subdirectory(src/vault/pthash)

if(VAULT_PTHASH_BUILD_TESTS)
endif()

if(VAULT_PTHASH_BUILD_EXAMPLES)
endif()

if(VAULT_PTHASH_BUILD_BENCHMARKS)
endif()

if(VAULT_PTHASH_CONFIG_FILE_PACKAGE)
  include(cmake/vault-config-file-package.cmake)
endif()
