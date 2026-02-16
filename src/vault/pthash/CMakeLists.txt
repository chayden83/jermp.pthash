find_package(Threads REQUIRED)

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
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/bucketers.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/dense_encoders.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/util.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/encoders.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/utils/hasher.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/single_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/dense_partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/partitioned_phf.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/mm_file/mm_file.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/essentials/essentials.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/bit_vector.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/elias_fano.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/rice_sequence.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/compact_vector.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/ranked_sequence.hpp
  ${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/darray.hpp
  
  #${PROJECT_SOURCE_DIR}/include/vault/pthash/bits/util.hpp
)

target_link_libraries(vault.pthash INTERFACE
  Threads::Threads
)

vault_install_targets(
  TARGETS vault.pthash
)

vault_install_export()
