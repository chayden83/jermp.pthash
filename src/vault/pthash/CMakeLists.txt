find_package(Threads REQUIRED)

FetchContent_Declare(extern.essentials
  URL https://github.com/jermp/essentials/archive/54bd98b.tar.gz
  URL_MD5 dd629e723c2a36a7ff2c317967112e23
)

FetchContent_Declare(extern.bits
  URL https://github.com/jermp/bits/archive/7464dc7.tar.gz
  URL_MD5 7c3d22e66f05a3241cf24831cd27438a
)

# FetchContent_Declare(extern.xxhash
# )

# FetchContent_Declare(extern.mm_file
# )

FetchContent_MakeAvailable(extern.essentials)
FetchContent_MakeAvailable(extern.bits)

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
)

target_link_libraries(vault.pthash INTERFACE
  Threads::Threads
)

vault_install_targets(
  TARGETS vault.pthash
)

vault_install_export()
