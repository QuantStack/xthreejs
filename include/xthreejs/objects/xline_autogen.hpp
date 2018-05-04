#ifndef XTHREE_LINE_HPP
#define XTHREE_LINE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"

namespace xthree
{
    //
    // line declaration
    //

    template<class D>
    class xline : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, material);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, geometry);


    protected:

        xline();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line = xw::xmaterialize<xline>;

    using line_generator = xw::xgenerator<xline>;

    //
    // line implementation
    //


    template <class D>
    inline void xline<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(material, state, buffers);
        xw::set_patch_from_property(geometry, state, buffers);
    }

    template <class D>
    inline void xline<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(material, patch, buffers);
        xw::set_property_from_patch(geometry, patch, buffers);
    }

    template <class D>
    inline xline<D>::xline()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline<D>::set_defaults()
    {
        this->_model_name() = "LineModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xline));
//}
#endif