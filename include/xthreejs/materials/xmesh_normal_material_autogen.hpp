#ifndef XTHREE_MESH_NORMAL_MATERIAL_HPP
#define XTHREE_MESH_NORMAL_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xmaterial_autogen.hpp"

namespace xthree
{
    //
    // mesh_normal_material declaration
    //

    template<class D>
    class xmesh_normal_material : public xmaterial<D>
    {
    public:

        using base_type = xmaterial<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(bool, derived_type, fog, false);
        XPROPERTY(bool, derived_type, lights, false);
        XPROPERTY(bool, derived_type, morphTargets, false);
        XPROPERTY(bool, derived_type, wireframe, false);
        XPROPERTY(double, derived_type, wireframeLinewidth, 1);


    protected:

        xmesh_normal_material();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using mesh_normal_material = xw::xmaterialize<xmesh_normal_material>;

    using mesh_normal_material_generator = xw::xgenerator<xmesh_normal_material>;

    //
    // mesh_normal_material implementation
    //


    template <class D>
    inline void xmesh_normal_material<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(morphTargets, state, buffers);
        xw::set_patch_from_property(wireframe, state, buffers);
        xw::set_patch_from_property(wireframeLinewidth, state, buffers);
    }

    template <class D>
    inline void xmesh_normal_material<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(morphTargets, patch, buffers);
        xw::set_property_from_patch(wireframe, patch, buffers);
        xw::set_property_from_patch(wireframeLinewidth, patch, buffers);
    }

    template <class D>
    inline xmesh_normal_material<D>::xmesh_normal_material()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmesh_normal_material<D>::set_defaults()
    {
        this->_model_name() = "MeshNormalMaterialModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xmesh_normal_material));
//}
#endif