#ifndef XTHREE_OBJECT3D_BASE_HPP
#define XTHREE_OBJECT3D_BASE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // object3d_base declaration
    //

    template<class D>
    class xobject3d_base : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(std::string, derived_type, type, "");
        XPROPERTY(std::vector<xw::xholder<xthree_widget>>, derived_type, children, std::vector<xw::xholder<xthree_widget>>({}));
        XPROPERTY(vector3, derived_type, up, vector3({0,1,0}));
        XPROPERTY(vector3, derived_type, position, vector3({0,0,0}));
        XPROPERTY(xthree::euler, derived_type, rotation, xthree::euler({0,0,0,"XYZ"}));
        XPROPERTY(vector4, derived_type, quaternion, vector4({0,0,0,1}));
        XPROPERTY(vector3, derived_type, scale, vector3({1,1,1}));
        XPROPERTY(matrix4, derived_type, modelViewMatrix, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));
        XPROPERTY(matrix3, derived_type, normalMatrix, matrix3({1,0,0,0,1,0,0,0,1}));
        XPROPERTY(matrix4, derived_type, matrix, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));
        XPROPERTY(matrix4, derived_type, matrixWorld, matrix4({1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}));
        XPROPERTY(bool, derived_type, matrixAutoUpdate, true);
        XPROPERTY(bool, derived_type, matrixWorldNeedsUpdate, false);
        XPROPERTY(bool, derived_type, visible, true);
        XPROPERTY(bool, derived_type, castShadow, false);
        XPROPERTY(bool, derived_type, receiveShadow, false);
        XPROPERTY(bool, derived_type, frustumCulled, true);
        XPROPERTY(int, derived_type, renderOrder, 0);


    protected:

        xobject3d_base();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using object3d_base = xw::xmaterialize<xobject3d_base>;

    using object3d_base_generator = xw::xgenerator<xobject3d_base>;

    //
    // object3d_base implementation
    //


    template <class D>
    inline void xobject3d_base<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
        xw::set_patch_from_property(children, state, buffers);
        xw::set_patch_from_property(up, state, buffers);
        xw::set_patch_from_property(position, state, buffers);
        xw::set_patch_from_property(rotation, state, buffers);
        xw::set_patch_from_property(quaternion, state, buffers);
        xw::set_patch_from_property(scale, state, buffers);
        xw::set_patch_from_property(modelViewMatrix, state, buffers);
        xw::set_patch_from_property(normalMatrix, state, buffers);
        xw::set_patch_from_property(matrix, state, buffers);
        xw::set_patch_from_property(matrixWorld, state, buffers);
        xw::set_patch_from_property(matrixAutoUpdate, state, buffers);
        xw::set_patch_from_property(matrixWorldNeedsUpdate, state, buffers);
        xw::set_patch_from_property(visible, state, buffers);
        xw::set_patch_from_property(castShadow, state, buffers);
        xw::set_patch_from_property(receiveShadow, state, buffers);
        xw::set_patch_from_property(frustumCulled, state, buffers);
        xw::set_patch_from_property(renderOrder, state, buffers);
    }

    template <class D>
    inline void xobject3d_base<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
        xw::set_property_from_patch(children, patch, buffers);
        xw::set_property_from_patch(up, patch, buffers);
        xw::set_property_from_patch(position, patch, buffers);
        xw::set_property_from_patch(rotation, patch, buffers);
        xw::set_property_from_patch(quaternion, patch, buffers);
        xw::set_property_from_patch(scale, patch, buffers);
        xw::set_property_from_patch(modelViewMatrix, patch, buffers);
        xw::set_property_from_patch(normalMatrix, patch, buffers);
        xw::set_property_from_patch(matrix, patch, buffers);
        xw::set_property_from_patch(matrixWorld, patch, buffers);
        xw::set_property_from_patch(matrixAutoUpdate, patch, buffers);
        xw::set_property_from_patch(matrixWorldNeedsUpdate, patch, buffers);
        xw::set_property_from_patch(visible, patch, buffers);
        xw::set_property_from_patch(castShadow, patch, buffers);
        xw::set_property_from_patch(receiveShadow, patch, buffers);
        xw::set_property_from_patch(frustumCulled, patch, buffers);
        xw::set_property_from_patch(renderOrder, patch, buffers);
    }

    template <class D>
    inline xobject3d_base<D>::xobject3d_base()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xobject3d_base<D>::set_defaults()
    {
        this->_model_name() = "Object3DBaseModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xobject3d_base));
//}
#endif