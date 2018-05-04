#ifndef XTHREE_CLOCK_HPP
#define XTHREE_CLOCK_HPP

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
    // clock declaration
    //

    template<class D>
    class xclock : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



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

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xclock));
//}
#endif