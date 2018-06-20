#ifndef XTHREE_CLOCK_HPP
#define XTHREE_CLOCK_HPP

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
    // clock declaration
    //

    template<class D>
    class xclock : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xclock();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using clock = xw::xmaterialize<xclock>;

    using clock_generator = xw::xgenerator<xclock>;

    //
    // clock implementation
    //


    template <class D>
    inline void xclock<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xclock<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xclock<D>::xclock()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xclock<D>::set_defaults()
    {
        this->_model_name() = "ClockModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xclock>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xclock>;
        extern template xw::xmaterialize<xthree::xclock>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xclock>>;
        extern template class xw::xgenerator<xthree::xclock>;
        extern template xw::xgenerator<xthree::xclock>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xclock>>;
    #endif
#endif

#endif