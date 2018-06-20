#ifndef XTHREE_DIRECT_GEOMETRY_HPP
#define XTHREE_DIRECT_GEOMETRY_HPP

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
    // direct_geometry declaration
    //

    template<class D>
    class xdirect_geometry : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xdirect_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using direct_geometry = xw::xmaterialize<xdirect_geometry>;

    using direct_geometry_generator = xw::xgenerator<xdirect_geometry>;

    //
    // direct_geometry implementation
    //


    template <class D>
    inline void xdirect_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdirect_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdirect_geometry<D>::xdirect_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdirect_geometry<D>::set_defaults()
    {
        this->_model_name() = "DirectGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xdirect_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xdirect_geometry>;
        extern template xw::xmaterialize<xthree::xdirect_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xdirect_geometry>>;
        extern template class xw::xgenerator<xthree::xdirect_geometry>;
        extern template xw::xgenerator<xthree::xdirect_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xdirect_geometry>>;
    #endif
#endif

#endif