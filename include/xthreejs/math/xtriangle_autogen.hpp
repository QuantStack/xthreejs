#ifndef XTHREE_TRIANGLE_HPP
#define XTHREE_TRIANGLE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // triangle declaration
    //

    template<class D>
    class xtriangle : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, a, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, b, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, c, vector3({0,0,0}));


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xtriangle();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using triangle = xw::xmaterialize<xtriangle>;

    using triangle_generator = xw::xgenerator<xtriangle>;

    //
    // triangle implementation
    //


    template <class D>
    inline void xtriangle<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(a, state, buffers);
        xw::set_patch_from_property(b, state, buffers);
        xw::set_patch_from_property(c, state, buffers);
    }

    template <class D>
    inline void xtriangle<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(a, patch, buffers);
        xw::set_property_from_patch(b, patch, buffers);
        xw::set_property_from_patch(c, patch, buffers);
    }

    template <class D>
    inline xtriangle<D>::xtriangle()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtriangle<D>::set_defaults()
    {
        this->_model_name() = "TriangleModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xtriangle>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xtriangle>;
        extern template xw::xmaterialize<xthree::xtriangle>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xtriangle>>;
        extern template class xw::xgenerator<xthree::xtriangle>;
        extern template xw::xgenerator<xthree::xtriangle>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xtriangle>>;
    #endif
#endif

#endif