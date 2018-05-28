#ifndef XTHREE_EDGES_GEOMETRY_HPP
#define XTHREE_EDGES_GEOMETRY_HPP

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
    // edges_geometry declaration
    //

    template<class D>
    class xedges_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xedges_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using edges_geometry = xw::xmaterialize<xedges_geometry>;

    using edges_geometry_generator = xw::xgenerator<xedges_geometry>;

    //
    // edges_geometry implementation
    //


    template <class D>
    inline void xedges_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xedges_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xedges_geometry<D>::xedges_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xedges_geometry<D>::set_defaults()
    {
        this->_model_name() = "EdgesGeometryModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xedges_geometry>& widget)
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
        extern template class xw::xmaterialize<xthree::xedges_geometry>;
        extern template xw::xmaterialize<xthree::xedges_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xedges_geometry>>;
        extern template class xw::xgenerator<xthree::xedges_geometry>;
        extern template xw::xgenerator<xthree::xedges_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xedges_geometry>>;
    #endif
#endif

#endif