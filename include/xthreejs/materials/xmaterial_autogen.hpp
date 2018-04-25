#ifndef XTHREE_MATERIAL_HPP
#define XTHREE_MATERIAL_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // material declaration
    //

    template<class D>
    class xmaterial : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, alphaTest, 0);
        XPROPERTY(std::string, derived_type, blendDst, "OneMinusSrcAlphaFactor", xenums::BlendFactors);
        XPROPERTY(double, derived_type, blendDstAlpha, 0);
        XPROPERTY(std::string, derived_type, blending, "NormalBlending", xenums::BlendingMode);
        XPROPERTY(std::string, derived_type, blendSrc, "SrcAlphaFactor", xenums::BlendFactors);
        XPROPERTY(double, derived_type, blendSrcAlpha, 0);
        XPROPERTY(std::string, derived_type, blendEquation, "AddEquation", xenums::Equations);
        XPROPERTY(double, derived_type, blendEquationAlpha, 0);
        XPROPERTY(bool, derived_type, clipIntersection, false);
        XPROPERTY(std::vector<xw::xholder<xthree_widget>>, derived_type, clippingPlanes, std::vector<xw::xholder<xthree_widget>>({}));
        XPROPERTY(bool, derived_type, clipShadows, false);
        XPROPERTY(bool, derived_type, colorWrite, true);
        XPROPERTY(xtl::xoptional<::xeus::xjson>, derived_type, defines);
        XPROPERTY(std::string, derived_type, depthFunc, "LessEqualDepth", xenums::DepthMode);
        XPROPERTY(bool, derived_type, depthTest, true);
        XPROPERTY(bool, derived_type, depthWrite, true);
        XPROPERTY(bool, derived_type, fog, true);
        XPROPERTY(bool, derived_type, lights, true);
        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(double, derived_type, overdraw, 0);
        XPROPERTY(bool, derived_type, polygonOffset, false);
        XPROPERTY(double, derived_type, polygonOffsetFactor, 0);
        XPROPERTY(double, derived_type, polygonOffsetUnits, 0);
        XPROPERTY(xtl::xoptional<std::string>, derived_type, precision);
        XPROPERTY(bool, derived_type, premultipliedAlpha, false);
        XPROPERTY(bool, derived_type, dithering, false);
        XPROPERTY(bool, derived_type, flatShading, false);
        XPROPERTY(std::string, derived_type, side, "FrontSide", xenums::Side);
        XPROPERTY(bool, derived_type, transparent, false);
        XPROPERTY(std::string, derived_type, type, "");
        XPROPERTY(std::string, derived_type, vertexColors, "NoColors", xenums::Colors);
        XPROPERTY(bool, derived_type, visible, true);
        XPROPERTY(double, derived_type, opacity, 1);

    protected:

        xmaterial();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using material = xw::xmaterialize<xmaterial>;

    using material_generator = xw::xgenerator<xmaterial>;

    //
    // material implementation
    //

    template <class D>
    inline void xmaterial<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(alphaTest, state, buffers);
        xw::set_patch_from_property(blendDst, state, buffers);
        xw::set_patch_from_property(blendDstAlpha, state, buffers);
        xw::set_patch_from_property(blending, state, buffers);
        xw::set_patch_from_property(blendSrc, state, buffers);
        xw::set_patch_from_property(blendSrcAlpha, state, buffers);
        xw::set_patch_from_property(blendEquation, state, buffers);
        xw::set_patch_from_property(blendEquationAlpha, state, buffers);
        xw::set_patch_from_property(clipIntersection, state, buffers);
        xw::set_patch_from_property(clippingPlanes, state, buffers);
        xw::set_patch_from_property(clipShadows, state, buffers);
        xw::set_patch_from_property(colorWrite, state, buffers);
        xw::set_patch_from_property(defines, state, buffers);
        xw::set_patch_from_property(depthFunc, state, buffers);
        xw::set_patch_from_property(depthTest, state, buffers);
        xw::set_patch_from_property(depthWrite, state, buffers);
        xw::set_patch_from_property(fog, state, buffers);
        xw::set_patch_from_property(lights, state, buffers);
        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(overdraw, state, buffers);
        xw::set_patch_from_property(polygonOffset, state, buffers);
        xw::set_patch_from_property(polygonOffsetFactor, state, buffers);
        xw::set_patch_from_property(polygonOffsetUnits, state, buffers);
        xw::set_patch_from_property(precision, state, buffers);
        xw::set_patch_from_property(premultipliedAlpha, state, buffers);
        xw::set_patch_from_property(dithering, state, buffers);
        xw::set_patch_from_property(flatShading, state, buffers);
        xw::set_patch_from_property(side, state, buffers);
        xw::set_patch_from_property(transparent, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
        xw::set_patch_from_property(vertexColors, state, buffers);
        xw::set_patch_from_property(visible, state, buffers);
        xw::set_patch_from_property(opacity, state, buffers);
    }

    template <class D>
    inline void xmaterial<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(alphaTest, patch, buffers);
        xw::set_property_from_patch(blendDst, patch, buffers);
        xw::set_property_from_patch(blendDstAlpha, patch, buffers);
        xw::set_property_from_patch(blending, patch, buffers);
        xw::set_property_from_patch(blendSrc, patch, buffers);
        xw::set_property_from_patch(blendSrcAlpha, patch, buffers);
        xw::set_property_from_patch(blendEquation, patch, buffers);
        xw::set_property_from_patch(blendEquationAlpha, patch, buffers);
        xw::set_property_from_patch(clipIntersection, patch, buffers);
        xw::set_property_from_patch(clippingPlanes, patch, buffers);
        xw::set_property_from_patch(clipShadows, patch, buffers);
        xw::set_property_from_patch(colorWrite, patch, buffers);
        xw::set_property_from_patch(defines, patch, buffers);
        xw::set_property_from_patch(depthFunc, patch, buffers);
        xw::set_property_from_patch(depthTest, patch, buffers);
        xw::set_property_from_patch(depthWrite, patch, buffers);
        xw::set_property_from_patch(fog, patch, buffers);
        xw::set_property_from_patch(lights, patch, buffers);
        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(overdraw, patch, buffers);
        xw::set_property_from_patch(polygonOffset, patch, buffers);
        xw::set_property_from_patch(polygonOffsetFactor, patch, buffers);
        xw::set_property_from_patch(polygonOffsetUnits, patch, buffers);
        xw::set_property_from_patch(precision, patch, buffers);
        xw::set_property_from_patch(premultipliedAlpha, patch, buffers);
        xw::set_property_from_patch(dithering, patch, buffers);
        xw::set_property_from_patch(flatShading, patch, buffers);
        xw::set_property_from_patch(side, patch, buffers);
        xw::set_property_from_patch(transparent, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
        xw::set_property_from_patch(vertexColors, patch, buffers);
        xw::set_property_from_patch(visible, patch, buffers);
        xw::set_property_from_patch(opacity, patch, buffers);
    }

    template <class D>
    inline xmaterial<D>::xmaterial()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xmaterial<D>::set_defaults()
    {
        this->_model_name() = "MaterialModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xmaterial));
//}
#endif