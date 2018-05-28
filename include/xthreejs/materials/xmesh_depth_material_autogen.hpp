#ifndef XTHREE_MESH_DEPTH_MATERIAL_HPP
#define XTHREE_MESH_DEPTH_MATERIAL_HPP

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
    // mesh_depth_material declaration
    //

    template<class D>
    class xmesh_depth_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, alphaMap);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, displacementMap);
        XPROPERTY(double, derived_type, displacementScale, 1);
        XPROPERTY(double, derived_type, displacementBias, 0);
        XPROPERTY(bool, derived_type, fog, false);
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, map);
        XPROPERTY(bool, derived_type, morphTargets, false);
        XPROPERTY(bool, derived_type, skinning, false);
        XPROPERTY(bool, derived_type, wireframe, false);
        XPROPERTY(double, derived_type, wireframeLinewidth, 1);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmesh_depth_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh_depth_material = xw::xmaterialize<xmesh_depth_material>;

    using mesh_depth_material_generator = xw::xgenerator<xmesh_depth_material>;

    //
    // mesh_depth_material implementation
    //


    template <class D>
    inline void xmesh_depth_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(alphaMap, state, buffers);
        xw::set_patch_from_property(displacementMap, state, buffers);
        xw::set_patch_from_property(displacementScale, state, buffers);
        xw::set_patch_from_property(displacementBias, state, buffers);
        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(map, state, buffers);
        xw::set_patch_from_property(morphTargets, state, buffers);
        xw::set_patch_from_property(skinning, state, buffers);
        xw::set_patch_from_property(wireframe, state, buffers);
        xw::set_patch_from_property(wireframeLinewidth, state, buffers);
    }

    template <class D>
    inline void xmesh_depth_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(alphaMap, patch, buffers);
        xw::set_property_from_patch(displacementMap, patch, buffers);
        xw::set_property_from_patch(displacementScale, patch, buffers);
        xw::set_property_from_patch(displacementBias, patch, buffers);
        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(map, patch, buffers);
        xw::set_property_from_patch(morphTargets, patch, buffers);
        xw::set_property_from_patch(skinning, patch, buffers);
        xw::set_property_from_patch(wireframe, patch, buffers);
        xw::set_property_from_patch(wireframeLinewidth, patch, buffers);
    }

    template <class D>
    inline xmesh_depth_material<D>::xmesh_depth_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh_depth_material<D>::set_defaults()
    {
        this->_model_name() = "MeshDepthMaterialModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xmesh_depth_material>& widget)
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
        extern template class xw::xmaterialize<xthree::xmesh_depth_material>;
        extern template xw::xmaterialize<xthree::xmesh_depth_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmesh_depth_material>>;
        extern template class xw::xgenerator<xthree::xmesh_depth_material>;
        extern template xw::xgenerator<xthree::xmesh_depth_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmesh_depth_material>>;
    #endif
#endif

#endif