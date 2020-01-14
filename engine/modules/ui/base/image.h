#pragma once

#include "engine/core/render/base/mesh/Mesh.h"
#include "engine/core/render/base/Material.h"
#include "engine/core/render/base/Renderable.h"
#include "../render/vertex_format.h"
#include "render.h"

namespace Echo
{
    class UiImage : public UiRender
    {
        ECHO_CLASS(UiImage, UiRender)
        
    public:
        UiImage();
        virtual ~UiImage();
        
        // texture res path
        void setTextureRes(const ResourcePath& path);
        const ResourcePath& getTextureRes() { return m_textureRes; }
        
        // width
        i32 getWidth() const { return m_width; }
        void setWidth(i32 width);
        
        // width
        i32 getHeight() const { return m_height; }
        void setHeight(i32 height);

    protected:
        // build drawable
        void buildRenderable();
        
        // update
        virtual void update_self() override;
        
        // update vertex buffer
        void updateMeshBuffer();
        
        // build mesh data by drawables data
        void buildMeshData(Ui::VertexArray& oVertices, Ui::IndiceArray& oIndices);
        
        // clear
        void clear();
        void clearRenderable();
        
    private:
        ResourcePath            m_textureRes;
        Mesh*                   m_mesh;            // Geometry Data for render
        MaterialPtr             m_material;        // Material Instance
        Renderable*             m_renderable;
        Matrix4                 m_matWVP;
        i32                     m_width;
        i32                     m_height;
    };
}
