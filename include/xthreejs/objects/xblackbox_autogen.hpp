#ifndef XTHREE_BLACKBOX_HPP
#define XTHREE_BLACKBOX_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // blackbox declaration
    //

    template<class D>
    class xblackbox : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xblackbox();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using blackbox = xw::xmaterialize<xblackbox>;

    using blackbox_generator = xw::xgenerator<xblackbox>;

    //
    // blackbox implementation
    //

    template <class D>
    inline void xblackbox<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xblackbox<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xblackbox<D>::xblackbox()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xblackbox<D>::set_defaults()
    {
        this->_model_name() = "BlackboxModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xblackbox));
//}
#endif