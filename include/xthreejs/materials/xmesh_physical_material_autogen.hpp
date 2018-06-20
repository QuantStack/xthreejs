#ifndef XTHREE_MESH_PHYSICAL_MATERIAL_HPP
#define XTHREE_MESH_PHYSICAL_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmesh_standard_material_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // mesh_physical_material declaration
    //

    template<class D>
    class xmesh_physical_material : public xmesh_standard_material<D>
    {
    public:

        using base_type = xmesh_standard_material<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, clearCoat, 0);
        XPROPERTY(double, derived_type, clearCoatRoughness, 0);
        XPROPERTY(xtl::xoptional<::xeus::xjson>, derived_type, defines, ::xeus::xjson::parse(R"({"PHYSICAL":""})"));
        XPROPERTY(double, derived_type, reflectivity, 0.5);
        XPROPERTY(std::string, derived_type, type, "MeshPhysicalMaterial");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xmesh_physical_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh_physical_material = xw::xmaterialize<xmesh_physical_material>;

    using mesh_physical_material_generator = xw::xgenerator<xmesh_physical_material>;

    //
    // mesh_physical_material implementation
    //


    template <class D>
    inline void xmesh_physical_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(clearCoat, state, buffers);
        xw::set_patch_from_property(clearCoatRoughness, state, buffers);
        xw::set_patch_from_property(defines, state, buffers);
        xw::set_patch_from_property(reflectivity, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xmesh_physical_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(clearCoat, patch, buffers);
        xw::set_property_from_patch(clearCoatRoughness, patch, buffers);
        xw::set_property_from_patch(defines, patch, buffers);
        xw::set_property_from_patch(reflectivity, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xmesh_physical_material<D>::xmesh_physical_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh_physical_material<D>::set_defaults()
    {
        this->_model_name() = "MeshPhysicalMaterialModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xmesh_physical_material>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xmesh_physical_material>;
        extern template xw::xmaterialize<xthree::xmesh_physical_material>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xmesh_physical_material>>;
        extern template class xw::xgenerator<xthree::xmesh_physical_material>;
        extern template xw::xgenerator<xthree::xmesh_physical_material>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xmesh_physical_material>>;
    #endif
#endif

#endif