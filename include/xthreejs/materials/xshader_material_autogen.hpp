#ifndef XTHREE_SHADER_MATERIAL_HPP
#define XTHREE_SHADER_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // shader_material declaration
    //

    template<class D>
    class xshader_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(::xeus::xjson, derived_type, uniforms, ::xeus::xjson::object());
        XPROPERTY(bool, derived_type, clipping, false);
        XPROPERTY(::xeus::xjson, derived_type, extensions, ::xeus::xjson::object());
        XPROPERTY(bool, derived_type, fog, false);
        XPROPERTY(std::string, derived_type, fragmentShader, "");
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(double, derived_type, linewidth, 1);
        XPROPERTY(bool, derived_type, morphNormals, false);
        XPROPERTY(bool, derived_type, morphTargets, false);
        XPROPERTY(bool, derived_type, flatShading, false);
        XPROPERTY(bool, derived_type, skinning, false);
        XPROPERTY(std::string, derived_type, vertexShader, "");
        XPROPERTY(bool, derived_type, wireframe, false);
        XPROPERTY(double, derived_type, wireframeLinewidth, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xshader_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using shader_material = xw::xmaterialize<xshader_material>;

    using shader_material_generator = xw::xgenerator<xshader_material>;

    //
    // shader_material implementation
    //


    template <class D>
    inline void xshader_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(uniforms, state, buffers);
        xw::set_patch_from_property(clipping, state, buffers);
        xw::set_patch_from_property(extensions, state, buffers);
        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(fragmentShader, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(linewidth, state, buffers);
        xw::set_patch_from_property(morphNormals, state, buffers);
        xw::set_patch_from_property(morphTargets, state, buffers);
        xw::set_patch_from_property(flatShading, state, buffers);
        xw::set_patch_from_property(skinning, state, buffers);
        xw::set_patch_from_property(vertexShader, state, buffers);
        xw::set_patch_from_property(wireframe, state, buffers);
        xw::set_patch_from_property(wireframeLinewidth, state, buffers);
    }

    template <class D>
    inline void xshader_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(uniforms, patch, buffers);
        xw::set_property_from_patch(clipping, patch, buffers);
        xw::set_property_from_patch(extensions, patch, buffers);
        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(fragmentShader, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(linewidth, patch, buffers);
        xw::set_property_from_patch(morphNormals, patch, buffers);
        xw::set_property_from_patch(morphTargets, patch, buffers);
        xw::set_property_from_patch(flatShading, patch, buffers);
        xw::set_property_from_patch(skinning, patch, buffers);
        xw::set_property_from_patch(vertexShader, patch, buffers);
        xw::set_property_from_patch(wireframe, patch, buffers);
        xw::set_property_from_patch(wireframeLinewidth, patch, buffers);
    }

    template <class D>
    inline xshader_material<D>::xshader_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xshader_material<D>::set_defaults()
    {
        this->_model_name() = "ShaderMaterialModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xshader_material>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xshader_material>;
        extern template xw::xmaterialize<xthree::xshader_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xshader_material>>;
        extern template class xw::xgenerator<xthree::xshader_material>;
        extern template xw::xgenerator<xthree::xshader_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xshader_material>>;
    #endif
#endif

#endif