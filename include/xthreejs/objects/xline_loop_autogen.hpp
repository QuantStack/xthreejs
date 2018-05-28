#ifndef XTHREE_LINE_LOOP_HPP
#define XTHREE_LINE_LOOP_HPP

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
    // line_loop declaration
    //

    template<class D>
    class xline_loop : public xline<D>
    {
    public:

        using base_type = xline<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xline_loop();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line_loop = xw::xmaterialize<xline_loop>;

    using line_loop_generator = xw::xgenerator<xline_loop>;

    //
    // line_loop implementation
    //


    template <class D>
    inline void xline_loop<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xline_loop<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xline_loop<D>::xline_loop()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline_loop<D>::set_defaults()
    {
        this->_model_name() = "LineLoopModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xline_loop>& widget)
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
        extern template class xw::xmaterialize<xthree::xline_loop>;
        extern template xw::xmaterialize<xthree::xline_loop>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xline_loop>>;
        extern template class xw::xgenerator<xthree::xline_loop>;
        extern template xw::xgenerator<xthree::xline_loop>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xline_loop>>;
    #endif
#endif

#endif