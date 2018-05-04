#ifndef XTHREE_MESH_PHYSICAL_MATERIAL_HPP
#define XTHREE_MESH_PHYSICAL_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmesh_standard_material_autogen.hpp"

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
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, clearCoat, 0);
        XPROPERTY(double, derived_type, clearCoatRoughness, 0);
        XPROPERTY(xtl::xoptional<::xeus::xjson>, derived_type, defines, ::xeus::xjson::parse(R"({"PHYSICAL":""})"));
        XPROPERTY(double, derived_type, reflectivity, 0.5);


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
    }

    template <class D>
    inline void xmesh_physical_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(clearCoat, patch, buffers);
        xw::set_property_from_patch(clearCoatRoughness, patch, buffers);
        xw::set_property_from_patch(defines, patch, buffers);
        xw::set_property_from_patch(reflectivity, patch, buffers);
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

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xmesh_physical_material));
//}
#endif