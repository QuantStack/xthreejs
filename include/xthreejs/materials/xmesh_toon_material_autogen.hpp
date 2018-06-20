#ifndef XTHREE_MESH_TOON_MATERIAL_HPP
#define XTHREE_MESH_TOON_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmesh_phong_material_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // mesh_toon_material declaration
    //

    template<class D>
    class xmesh_toon_material : public xmesh_phong_material<D>
    {
    public:

        using base_type = xmesh_phong_material<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, gradientMap);
        XPROPERTY(std::string, derived_type, type, "MeshToonMaterial");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmesh_toon_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh_toon_material = xw::xmaterialize<xmesh_toon_material>;

    using mesh_toon_material_generator = xw::xgenerator<xmesh_toon_material>;

    //
    // mesh_toon_material implementation
    //


    template <class D>
    inline void xmesh_toon_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(gradientMap, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xmesh_toon_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(gradientMap, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xmesh_toon_material<D>::xmesh_toon_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh_toon_material<D>::set_defaults()
    {
        this->_model_name() = "MeshToonMaterialModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmesh_toon_material>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xmesh_toon_material>;
        extern template xw::xmaterialize<xthree::xmesh_toon_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmesh_toon_material>>;
        extern template class xw::xgenerator<xthree::xmesh_toon_material>;
        extern template xw::xgenerator<xthree::xmesh_toon_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmesh_toon_material>>;
    #endif
#endif

#endif