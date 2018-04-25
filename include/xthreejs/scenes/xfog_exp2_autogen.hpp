#ifndef XTHREE_FOG_EXP2_HPP
#define XTHREE_FOG_EXP2_HPP

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
    // fog_exp2 declaration
    //

    template<class D>
    class xfog_exp2 : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(xw::html_color, derived_type, color, "white");
        XPROPERTY(double, derived_type, density, 0.00025);

    protected:

        xfog_exp2();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using fog_exp2 = xw::xmaterialize<xfog_exp2>;

    using fog_exp2_generator = xw::xgenerator<xfog_exp2>;

    //
    // fog_exp2 implementation
    //

    template <class D>
    inline void xfog_exp2<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(density, state, buffers);
    }

    template <class D>
    inline void xfog_exp2<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(density, patch, buffers);
    }

    template <class D>
    inline xfog_exp2<D>::xfog_exp2()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfog_exp2<D>::set_defaults()
    {
        this->_model_name() = "FogExp2Model";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xfog_exp2));
//}
#endif