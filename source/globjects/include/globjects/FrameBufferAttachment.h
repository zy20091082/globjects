#pragma once

#include <string>

#include <glbinding/gl/types.h>

#include <globjects-base/Referenced.h>

#include <globjects/globjects_api.h>

namespace glo 
{

class TextureAttachment;
class RenderBufferAttachment;
class FrameBufferObject;

/** \brief Wraps attachments to a FrameBufferObject.
    
    Normally, FrameBufferAttachments are created using the API of FrameBufferObject.
    
    \see FrameBufferObject
    \see TextureAttachment
    \see RenderBufferAttachment
*/
class GLOBJECTS_API FrameBufferAttachment : public Referenced
{
public:
    FrameBufferAttachment(FrameBufferObject * fbo, gl::GLenum attachment);

	gl::GLenum attachment() const;

    gl::GLint getParameter(gl::GLenum pname) const;

	virtual bool isTextureAttachment() const;
	virtual bool isRenderBufferAttachment() const;

    TextureAttachment * asTextureAttachment();
    const TextureAttachment * asTextureAttachment() const;
    RenderBufferAttachment * asRenderBufferAttachment();
    const RenderBufferAttachment * asRenderBufferAttachment() const;

	std::string attachmentString() const;

protected:
    FrameBufferObject * m_fbo;
	gl::GLenum m_attachment;
};

} // namespace glo