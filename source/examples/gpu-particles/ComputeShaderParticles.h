#pragma once

#include <globjects-base/ref_ptr.h>

#include <globjects/VertexArrayObject.h>
#include <globjects/Program.h>
#include <globjects/Buffer.h>
#include <globjects/Texture.h>
#include <globjects/FrameBufferObject.h>

#include <globjects-utils/ScreenAlignedQuad.h>

#include "AbstractParticleTechnique.h"

class ComputeShaderParticles : public AbstractParticleTechnique
{
public:
    ComputeShaderParticles(
        const std::vector<glm::vec4> & positions
    ,   const std::vector<glm::vec4> & velocities
    ,   const glo::Texture & forces
    ,   const gloutils::Camera & camera);
    virtual ~ComputeShaderParticles();

    virtual void initialize() override;
    virtual void reset() override;

    virtual void step(float elapsed) override;
    virtual void draw(float elapsed) override;

    virtual void resize() override;

protected:
    glo::ref_ptr<glo::Buffer> m_positionsSSBO;
    glo::ref_ptr<glo::Buffer> m_velocitiesSSBO;

    glo::ref_ptr<glo::Program> m_computeProgram;
    glo::ref_ptr<glo::Program> m_drawProgram;

    glo::ref_ptr<glo::VertexArrayObject> m_vao;

    glo::ref_ptr<glo::FrameBufferObject> m_fbo;
    glo::ref_ptr<glo::Texture> m_color;

    glo::ref_ptr<gloutils::ScreenAlignedQuad> m_quad;
    glo::ref_ptr<gloutils::ScreenAlignedQuad> m_clear;

    glm::uvec3 m_workGroupSize;
};
