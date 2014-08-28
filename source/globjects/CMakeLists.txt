
# Target
set(target globjects)
message(STATUS "Lib ${target}")

#
# External libraries
#

find_package(GLM REQUIRED)
find_package(GLBinding REQUIRED)

#
# Includes
#

include_directories(
    ${GLM_INCLUDE_DIR}
    ${GLBINDING_INCLUDES}
)

include_directories(
    BEFORE
    ${CMAKE_SOURCE_DIR}/source/globjects-base/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#
# Libraries
#

set(libs
    ${GLBINDING_LIBRARIES}
    globjects-base
)

#
# Compiler definitions
#

if (OPTION_BUILD_STATIC)
    add_definitions("-D${META_PROJECT_NAME_UPPER}_STATIC")
else()
    add_definitions("-DGLOBJECTS_EXPORTS")
endif()

if (OPTION_ERRORS_AS_EXCEPTION)
    add_definitions("-DGLOBJECTS_GL_ERROR_RAISE_EXCEPTION")
else()
    add_definitions("-D_HAS_EXCEPTIONS=0")
endif()

# for compatibility between glm 0.9.4 and 0.9.5
add_definitions("-DGLM_FORCE_RADIANS")

#
# Sources
#

set(include_path "${CMAKE_CURRENT_SOURCE_DIR}/include/${target}")
set(source_path "${CMAKE_CURRENT_SOURCE_DIR}/source")

set(sources
	${source_path}/AbstractState.cpp
	${source_path}/AbstractUniform.cpp
	${source_path}/Buffer.cpp
	${source_path}/Capability.cpp
	${source_path}/constants.cpp
	${source_path}/container_helpers.hpp
	${source_path}/DebugInfo.cpp
	${source_path}/DebugMessage.cpp
	${source_path}/Error.cpp
	${source_path}/FrameBufferAttachment.cpp
	${source_path}/FrameBufferObject.cpp
	${source_path}/glbindinglogging.cpp
	${source_path}/glmlogging.cpp
	${source_path}/globjects.cpp
	${source_path}/implementations/AbstractProgramBinaryImplementation.h
	${source_path}/implementations/BindlessBufferImplementation.cpp
	${source_path}/implementations/BindlessEXTBufferImplementation.cpp
	${source_path}/implementations/ShadingLanguageIncludeImplementation.cpp
	${source_path}/implementations/DebugImplementation.cpp
	${source_path}/implementations/LegacyUniformImplementation.cpp
	${source_path}/implementations/ShadingLanguageIncludeImplementation.h
	${source_path}/implementations/NoProgramBinaryImplementation.cpp
	${source_path}/implementations/DebugImplementation.h
	${source_path}/implementations/AbstractFrameBufferImplementation.h
	${source_path}/implementations/NoShadingLanguageIncludeImplementation.cpp
	${source_path}/implementations/LegacyFrameBufferImplementation.h
	${source_path}/implementations/AbstractDebugImplementation.cpp
	${source_path}/implementations/LegacyBufferImplementation.cpp
	${source_path}/implementations/FallbackDebugImplementation.cpp
	${source_path}/implementations/LegacyBufferImplementation.h
	${source_path}/implementations/AbstractBufferImplementation.h
	${source_path}/implementations/NoProgramBinaryImplementation.h
	${source_path}/implementations/BindlessFrameBufferImplementation.cpp
	${source_path}/implementations/BindlessEXTFrameBufferImplementation.cpp
	${source_path}/implementations/LegacyUniformImplementation.h
	${source_path}/implementations/GetProgramBinaryImplementation.cpp
	${source_path}/implementations/BindlessEXTBufferImplementation.h
	${source_path}/implementations/NoShadingLanguageIncludeImplementation.h
	${source_path}/implementations/BindlessUniformImplementation.cpp
	${source_path}/implementations/AbstractDebugImplementation.h
	${source_path}/implementations/FallbackDebugImplementation.h
	${source_path}/implementations/AbstractBufferImplementation.cpp
	${source_path}/implementations/AbstractProgramBinaryImplementation.cpp
	${source_path}/implementations/GetProgramBinaryImplementation.h
	${source_path}/implementations/AbstractShadingLanguageIncludeImplementation.h
	${source_path}/implementations/BindlessUniformImplementation.h
	${source_path}/implementations/AbstractShadingLanguageIncludeImplementation.cpp
	${source_path}/implementations/AbstractUniformImplementation.h
	${source_path}/implementations/AbstractUniformImplementation.cpp
	${source_path}/implementations/BindlessFrameBufferImplementation.h
	${source_path}/implementations/BindlessEXTFrameBufferImplementation.h
	${source_path}/implementations/AbstractFrameBufferImplementation.cpp
	${source_path}/implementations/LegacyFrameBufferImplementation.cpp
	${source_path}/IncludeProcessor.cpp
	${source_path}/IncludeProcessor.h
	${source_path}/LocationIdentity.cpp
	${source_path}/memory.cpp
	${source_path}/NamedString.cpp
	${source_path}/Object.cpp
	${source_path}/objectlogging.cpp
	${source_path}/ObjectVisitor.cpp
	${source_path}/pixelformat.cpp
	${source_path}/pixelformat.h
	${source_path}/ProgramBinary.cpp
	${source_path}/Program.cpp
	${source_path}/Query.cpp
	${source_path}/registry/ObjectRegistry.h
	${source_path}/registry/ExtensionRegistry.h
	${source_path}/registry/NamedStringRegistry.cpp
	${source_path}/registry/ImplementationRegistry.cpp
	${source_path}/registry/ExtensionRegistry.cpp
	${source_path}/registry/ObjectRegistry.cpp
	${source_path}/registry/NamedStringRegistry.h
	${source_path}/registry/ImplementationRegistry.h
	${source_path}/registry/Registry.cpp
	${source_path}/registry/Registry.h
	${source_path}/RenderBufferAttachment.cpp
	${source_path}/RenderBufferObject.cpp
	${source_path}/Resource.cpp
	${source_path}/Resource.h
	${source_path}/Sampler.cpp
	${source_path}/Shader.cpp
	${source_path}/State.cpp
	${source_path}/StateSetting.cpp
	${source_path}/Sync.cpp
	${source_path}/TextureAttachment.cpp
	${source_path}/Texture.cpp
	${source_path}/TransformFeedback.cpp
	${source_path}/UniformBlock.cpp
	${source_path}/VertexArrayObject.cpp
	${source_path}/VertexAttributeBinding.cpp
	${source_path}/VertexAttributeBindingImplementation.cpp
	${source_path}/VertexAttributeBindingImplementation.h
)

set(api_includes
	${include_path}/AbstractState.h
	${include_path}/AbstractState.hpp
	${include_path}/AbstractUniform.h
	${include_path}/AbstractUniform.hpp
	${include_path}/Buffer.h
	${include_path}/Buffer.hpp
	${include_path}/Capability.h
	${include_path}/constants.h
	${include_path}/DebugInfo.h
	${include_path}/DebugMessage.h
	${include_path}/Error.h
	${include_path}/Extension.h
	${include_path}/FrameBufferAttachment.h
	${include_path}/FrameBufferObject.h
	${include_path}/glbindinglogging.h
	${include_path}/glmlogging.h
	${include_path}/globjects_api.h
	${include_path}/globjects.h
	${include_path}/globjects.hpp
	${include_path}/LocationIdentity.h
	${include_path}/logging.h
	${include_path}/memory.h
	${include_path}/NamedString.h
	${include_path}/Object.h
	${include_path}/objectlogging.h
	${include_path}/objectlogging.hpp
	${include_path}/ObjectVisitor.h
	${include_path}/ProgramBinary.h
	${include_path}/Program.h
	${include_path}/Program.hpp
	${include_path}/Query.h
	${include_path}/RenderBufferAttachment.h
	${include_path}/RenderBufferObject.h
	${include_path}/Sampler.h
	${include_path}/Shader.h
	${include_path}/State.h
	${include_path}/StateSetting.h
	${include_path}/StateSetting.hpp
	${include_path}/Sync.h
	${include_path}/TextureAttachment.h
	${include_path}/Texture.h
	${include_path}/TextureHandle.h
	${include_path}/TransformFeedback.h
	${include_path}/TransformFeedback.hpp
	${include_path}/UniformBlock.h
	${include_path}/Uniform.h
	${include_path}/Uniform.hpp
	${include_path}/VertexArrayObject.h
	${include_path}/VertexAttributeBinding.h
)

# Group source files
set(header_group "Header Files (API)")
set(source_group "Source Files")
source_group_by_path(${include_path} "\\\\.h$|\\\\.hpp$" 
    ${header_group} ${api_includes})
source_group_by_path(${source_path} "\\\\.cpp$|\\\\.c$|\\\\.h$|\\\\.hpp$" 
    ${source_group} ${sources})

#
# Build library
#

add_library(${target} ${api_includes} ${sources})

target_link_libraries(${target} ${libs})

set_target_properties(${target}
    PROPERTIES
    LINKER_LANGUAGE              CXX
    FOLDER                      "${IDE_FOLDER}"
    COMPILE_DEFINITIONS_DEBUG   "${DEFAULT_COMPILE_DEFS_DEBUG}"
    COMPILE_DEFINITIONS_RELEASE "${DEFAULT_COMPILE_DEFS_RELEASE}"
    COMPILE_FLAGS               "${DEFAULT_COMPILE_FLAGS}"
    LINK_FLAGS_DEBUG            "${DEFAULT_LINKER_FLAGS_DEBUG}"
    LINK_FLAGS_RELEASE          "${DEFAULT_LINKER_FLAGS_RELEASE}"
    DEBUG_POSTFIX               "d${DEBUG_POSTFIX}"
    INCLUDE_PATH	            ${include_path})

#
# Deployment
#

# Library
install(TARGETS ${target}
    RUNTIME DESTINATION ${INSTALL_BIN}
    LIBRARY DESTINATION ${INSTALL_SHARED}
    ARCHIVE DESTINATION ${INSTALL_LIB}
)

# Header files
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/${target} DESTINATION ${INSTALL_INCLUDE})