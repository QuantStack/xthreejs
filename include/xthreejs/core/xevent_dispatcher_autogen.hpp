#ifndef XTHREE_EVENT_DISPATCHER_HPP
#define XTHREE_EVENT_DISPATCHER_HPP

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
    // event_dispatcher declaration
    //

    template<class D>
    class xevent_dispatcher : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xevent_dispatcher();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using event_dispatcher = xw::xmaterialize<xevent_dispatcher>;

    using event_dispatcher_generator = xw::xgenerator<xevent_dispatcher>;

    //
    // event_dispatcher implementation
    //


    template <class D>
    inline void xevent_dispatcher<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xevent_dispatcher<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xevent_dispatcher<D>::xevent_dispatcher()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xevent_dispatcher<D>::set_defaults()
    {
        this->_model_name() = "EventDispatcherModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xevent_dispatcher>& widget)
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
        extern template class xw::xmaterialize<xthree::xevent_dispatcher>;
        extern template xw::xmaterialize<xthree::xevent_dispatcher>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xevent_dispatcher>>;
        extern template class xw::xgenerator<xthree::xevent_dispatcher>;
        extern template xw::xgenerator<xthree::xevent_dispatcher>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xevent_dispatcher>>;
    #endif
#endif

#endif