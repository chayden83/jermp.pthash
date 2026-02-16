find_package(Threads REQUIRED)

FetchContent_Declare(vault.pthash.essentials
  URL https://github.com/chayden83/jermp.essentials/archive/22c1b51.tar.gz
  URL_MD5 ea55d4d45139cb12e4fc1e95b018b468
)

FetchContent_Declare(vault.pthash.bits
  URL https://github.com/chayden83/jermp.bits/archive/e52452d.tar.gz
  URL_MD5 6117a1dcaa3f373f05c539a93d71aa4d
)

FetchContent_MakeAvailable(vault.pthash.essentials)
FetchContent_MakeAvailable(vault.pthash.bits)

vault_add_header_only_library(vault.pthash)

target_sources(vault.pthash PUBLIC FILE_SET HEADERS BASE_DIRS ${PROJECT_SOURCE_DIR}/include FILES
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/internal_memory_builder_partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/external_memory_builder_partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/internal_memory_builder_single_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/search_util.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/search.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/util.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/builders/external_memory_builder_single_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/pthash.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/logger.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/bucketers.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/dense_encoders.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/util.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/encoders.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/hasher.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/single_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/dense_partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/mm_file/mm_file.hpp
)

target_link_libraries(vault.pthash INTERFACE
  Threads::Threads
  vault::pthash.essentials
  vault::pthash.bits
)

vault_install_targets(
  TARGETS vault.pthash
)

vault_install_export()
