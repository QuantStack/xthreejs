#ifndef XTHREE_PARAMETRIC_GEOMETRY_HPP
#define XTHREE_PARAMETRIC_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // parametric_geometry declaration
    //

    template<class D>
    class xparametric_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, func, R"(function (u,v) { return THREE.Vector3(); })");
        XPROPERTY(int, derived_type, slices, 3);
        XPROPERTY(int, derived_type, stacks, 3);
        XPROPERTY(std::string, derived_type, type, "ParametricGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xparametric_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using parametric_geometry = xw::xmaterialize<xparametric_geometry>;

    using parametric_geometry_generator = xw::xgenerator<xparametric_geometry>;

    //
    // parametric_geometry implementation
    //


    template <class D>
    inline void xparametric_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(func, state, buffers);
        xw::set_patch_from_property(slices, state, buffers);
        xw::set_patch_from_property(stacks, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xparametric_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(func, patch, buffers);
        xw::set_property_from_patch(slices, patch, buffers);
        xw::set_property_from_patch(stacks, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xparametric_geometry<D>::xparametric_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xparametric_geometry<D>::set_defaults()
    {
        this->_model_name() = "ParametricGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xparametric_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xparametric_geometry>;
        extern template xw::xmaterialize<xthree::xparametric_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xparametric_geometry>>;
        extern template class xw::xgenerator<xthree::xparametric_geometry>;
        extern template xw::xgenerator<xthree::xparametric_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xparametric_geometry>>;
    #endif
#endif

#endif