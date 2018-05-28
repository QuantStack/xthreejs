#ifndef XTHREE_LINE_SEGMENTS_HPP
#define XTHREE_LINE_SEGMENTS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xline_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // line_segments declaration
    //

    template<class D>
    class xline_segments : public xline<D>
    {
    public:

        using base_type = xline<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xline_segments();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_segments = xw::xmaterialize<xline_segments>;

    using line_segments_generator = xw::xgenerator<xline_segments>;

    //
    // line_segments implementation
    //


    template <class D>
    inline void xline_segments<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xline_segments<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xline_segments<D>::xline_segments()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_segments<D>::set_defaults()
    {
        this->_model_name() = "LineSegmentsModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xline_segments>& widget)
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
        extern template class xw::xmaterialize<xthree::xline_segments>;
        extern template xw::xmaterialize<xthree::xline_segments>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xline_segments>>;
        extern template class xw::xgenerator<xthree::xline_segments>;
        extern template xw::xgenerator<xthree::xline_segments>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xline_segments>>;
    #endif
#endif

#endif