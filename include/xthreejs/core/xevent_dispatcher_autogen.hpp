#ifndef XTHREE_EVENT_DISPATCHER_HPP
#define XTHREE_EVENT_DISPATCHER_HPP

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
    // event_dispatcher declaration
    //

    template<class D>
    class xevent_dispatcher : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



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
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xevent_dispatcher));
//}
#endif