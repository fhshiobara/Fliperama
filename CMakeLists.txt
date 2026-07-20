cmake_minimum_required(VERSION 3.16)

# ============================================================
# Nome do Novo Projeto: Fliperama
# ============================================================
project(Fliperama LANGUAGES CXX)

set(EXECUTAVEL ${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ============================================================
# SFML (Configurado para o seu Mac via Homebrew)
# ============================================================
set(SFML_DIR "/opt/homebrew/lib/cmake/SFML")

find_package(SFML 2.6 REQUIRED COMPONENTS
    graphics
    window
    system
    audio
)

include_directories(include)

# ============================================================
# Copia a pasta assets para a pasta de build
# ============================================================
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# ============================================================
# Headers (apenas para aparecerem na IDE)
# ============================================================
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS
    "include/*.h"
    "include/*.hpp"
)

# ============================================================
# Assets (apenas para aparecerem na IDE)
# ============================================================
file(GLOB_RECURSE ASSET_FILES CONFIGURE_DEPENDS
    "assets/*"
)

# ============================================================
# Arquivos fonte (.cpp)
# ============================================================
set(SOURCES
    src/main.cpp
    src/Entidade.cpp
    src/Bola.cpp
    src/Raquete.cpp
    src/Pong.cpp
    src/GerenciadorGrafico.cpp
    
    # Adicione novos arquivos .cpp aqui embaixo quando criá-los
)

# ============================================================
# Criação do executável
# ============================================================
add_executable(${EXECUTAVEL}
    ${SOURCES}
    ${HEADER_FILES}
    ${ASSET_FILES}
)

# Garante que o Xcode use a pasta build como diretório de trabalho para achar os assets
if(APPLE)
    set_target_properties(${EXECUTAVEL} PROPERTIES
        VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_BINARY_DIR}"
        XCODE_ATTRIBUTE_CUSTOM_LAUNCH_PROPERTY "${CMAKE_BINARY_DIR}"
    )
endif()

# ============================================================
# Organiza as pastas na IDE (Xcode)
# ============================================================
source_group(
    TREE "${CMAKE_SOURCE_DIR}/include"
    PREFIX "Header Files"
    FILES ${HEADER_FILES}
)

source_group(
    TREE "${CMAKE_SOURCE_DIR}/assets"
    PREFIX "Assets"
    FILES ${ASSET_FILES}
)

# ============================================================
# Bibliotecas (Linkando a SFML ao Fliperama)
# ============================================================
target_link_libraries(${EXECUTAVEL}
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
)
