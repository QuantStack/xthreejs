#ifndef XTHREE_SPHERE_HPP
#define XTHREE_SPHERE_HPP

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
    // sphere declaration
    //

    template<class D>
    class xsphere : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, center, vector3({0,0,0}));
        XPROPERTY(double, derived_type, radius, 0);

    protected:

        xsphere();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using sphere = xw::xmaterialize<xsphere>;

    using sphere_generator = xw::xgenerator<xsphere>;

    //
    // sphere implementation
    //

    template <class D>
    inline void xsphere<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(center, state, buffers);
        xw::set_patch_from_property(radius, state, buffers);
    }

    template <class D>
    inline void xsphere<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(center, patch, buffers);
        xw::set_property_from_patch(radius, patch, buffers);
    }

    template <class D>
    inline xsphere<D>::xsphere()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xsphere<D>::set_defaults()
    {
        this->_model_name() = "SphereModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xsphere));
//}
#endif