#pragma once

#include <glow/glow.h>

namespace glow 
{

class Buffer;
class VertexArrayObject;
class VertexAttributeBindingImplementation;

class GLOW_API VertexAttributeBinding : public Referenced
{
	friend class VertexAttributeBindingImplementation;

public:
	VertexAttributeBinding(
        VertexArrayObject * vao
    ,   const GLint bindingIndex);
	~VertexAttributeBinding();

	void setAttribute(GLint attributeIndex);
	void setBuffer(
        Buffer * vbo
    ,   GLint baseoffset
    ,   GLint stride);

	void setFormat(
        GLint size
    ,   GLenum type
    ,   GLboolean normalized = GL_FALSE
    ,   GLuint relativeoffset = 0);
	void setIFormat(
        GLint size
    ,   GLenum type
    ,   GLuint relativeoffset = 0);
	void setLFormat(
        GLint size
    ,   GLuint relativeoffset = 0);

    GLint attributeIndex() const;
    GLint bindingIndex() const;
	Buffer * buffer() const;

protected:
    VertexArrayObject * m_vao;
   
    GLint m_bindingIndex;
    GLint m_attributeIndex;
    
    Buffer * m_vbo;

    VertexAttributeBindingImplementation * m_implementation;
};


// GL version specific implementations

class VertexAttributeBindingImplementation
{
public:
	VertexAttributeBindingImplementation(VertexAttributeBinding * binding);
	virtual ~VertexAttributeBindingImplementation();

    GLint attributeIndex() const;
    GLint bindingIndex() const;

	VertexArrayObject * vao() const;
	Buffer * vbo() const;

	virtual void bindAttribute(GLint attributeIndex) = 0;
	virtual void bindBuffer(
        Buffer * vbo
    ,   GLint baseoffset
    ,   GLint stride) = 0;

	virtual void setFormat(
        GLint size
    ,   GLenum type
    ,   GLboolean normalized
    ,   GLuint relativeoffset) = 0;
	
    virtual void setIFormat(GLint size, GLenum type, GLuint relativeoffset) = 0;
	virtual void setLFormat(GLint size, GLenum type, GLuint relativeoffset) = 0;

protected:
    VertexAttributeBinding * m_binding;
};


class VertexAttributeBinding_GL_3_2 : public VertexAttributeBindingImplementation
{
public:
	VertexAttributeBinding_GL_3_2(VertexAttributeBinding * binding);

	virtual void bindAttribute(GLint attributeIndex);
	virtual void bindBuffer(Buffer* vbo, GLint baseoffset, GLint stride);

	virtual void setFormat(GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	virtual void setIFormat(GLint size, GLenum type, GLuint relativeoffset);
	virtual void setLFormat(GLint size, GLenum type, GLuint relativeoffset);

protected:
    void finishIfComplete();
    void finish();

protected:
    struct Format
	{
		enum Method
        {
			O = 0
        ,   I = 1
        ,   L = 2
		};

		Format();
		Format(
            Method method
        ,   GLint size
        ,   GLenum type
        ,   GLboolean normalized
        ,   GLuint relativeoffset);

		Method method;

		GLint size;
		GLenum type;
		GLboolean normalized;
		GLuint relativeoffset;
	};

    Format m_format;
    GLint m_baseoffset;
    GLint m_stride;

    bool m_hasFormat;
    bool m_hasBuffer;
    bool m_hasAttribute;
};

class VertexAttributeBinding_GL_4_3 : public VertexAttributeBindingImplementation
{
public:
	VertexAttributeBinding_GL_4_3(VertexAttributeBinding* binding);

	virtual void bindAttribute(GLint attributeIndex);
	virtual void bindBuffer(Buffer * vbo, GLint baseoffset, GLint stride);

	virtual void setFormat(GLint size, GLenum type, GLboolean normalized, GLuint relativeoffset);
	virtual void setIFormat(GLint size, GLenum type, GLuint relativeoffset);
	virtual void setLFormat(GLint size, GLenum type, GLuint relativeoffset);
};

} // namespace glow
