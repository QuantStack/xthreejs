#ifndef XTHREE_AXES_HELPER_HPP
#define XTHREE_AXES_HELPER_HPP

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
    // axes_helper declaration
    //

    template<class D>
    class xaxes_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(double, derived_type, size, 1);

    protected:

        xaxes_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using axes_helper = xw::xmaterialize<xaxes_helper>;

    using axes_helper_generator = xw::xgenerator<xaxes_helper>;

    //
    // axes_helper implementation
    //

    template <class D>
    inline void xaxes_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(size, state, buffers);
    }

    template <class D>
    inline void xaxes_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(size, patch, buffers);
    }

    template <class D>
    inline xaxes_helper<D>::xaxes_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xaxes_helper<D>::set_defaults()
    {
        this->_model_name() = "AxesHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xaxes_helper));
//}
#endif