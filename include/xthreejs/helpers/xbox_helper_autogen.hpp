#ifndef XTHREE_BOX_HELPER_HPP
#define XTHREE_BOX_HELPER_HPP

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
    // box_helper declaration
    //

    template<class D>
    class xbox_helper : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, object);
        XPROPERTY(xtl::xoptional<xw::html_color>, derived_type, color, "#ffffff");

    protected:

        xbox_helper();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using box_helper = xw::xmaterialize<xbox_helper>;

    using box_helper_generator = xw::xgenerator<xbox_helper>;

    //
    // box_helper implementation
    //

    template <class D>
    inline void xbox_helper<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(object, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
    }

    template <class D>
    inline void xbox_helper<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(object, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
    }

    template <class D>
    inline xbox_helper<D>::xbox_helper()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbox_helper<D>::set_defaults()
    {
        this->_model_name() = "BoxHelperModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xbox_helper));
//}
#endif