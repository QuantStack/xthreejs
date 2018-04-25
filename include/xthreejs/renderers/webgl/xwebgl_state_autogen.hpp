#ifndef XTHREE_WEBGL_STATE_HPP
#define XTHREE_WEBGL_STATE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"

namespace xthree
{
    //
    // webgl_state declaration
    //

    template<class D>
    class xwebgl_state : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xwebgl_state();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using webgl_state = xw::xmaterialize<xwebgl_state>;

    using webgl_state_generator = xw::xgenerator<xwebgl_state>;

    //
    // webgl_state implementation
    //

    template <class D>
    inline void xwebgl_state<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xwebgl_state<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xwebgl_state<D>::xwebgl_state()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xwebgl_state<D>::set_defaults()
    {
        this->_model_name() = "WebGLStateModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xwebgl_state));
//}
#endif