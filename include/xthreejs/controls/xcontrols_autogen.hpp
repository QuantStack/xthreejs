#ifndef XTHREE_CONTROLS_HPP
#define XTHREE_CONTROLS_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // controls declaration
    //

    template<class D>
    class xcontrols : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xw::xholder<xthree_widget>, derived_type, controlling);

    protected:

        xcontrols();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using controls = xw::xmaterialize<xcontrols>;

    using controls_generator = xw::xgenerator<xcontrols>;

    //
    // controls implementation
    //

    template <class D>
    inline void xcontrols<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(controlling, state, buffers);
    }

    template <class D>
    inline void xcontrols<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(controlling, patch, buffers);
    }

    template <class D>
    inline xcontrols<D>::xcontrols()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xcontrols<D>::set_defaults()
    {
        this->_model_name() = "ControlsModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xcontrols));
//}
#endif