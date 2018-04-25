#ifndef XTHREE_SPOT_LIGHT_SHADOW_HPP
#define XTHREE_SPOT_LIGHT_SHADOW_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_shadow_autogen.hpp"

namespace xthree
{
    //
    // spot_light_shadow declaration
    //

    template<class D>
    class xspot_light_shadow : public xlight_shadow<D>
    {
    public:

        using base_type = xlight_shadow<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xspot_light_shadow();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using spot_light_shadow = xw::xmaterialize<xspot_light_shadow>;

    using spot_light_shadow_generator = xw::xgenerator<xspot_light_shadow>;

    //
    // spot_light_shadow implementation
    //

    template <class D>
    inline void xspot_light_shadow<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xspot_light_shadow<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xspot_light_shadow<D>::xspot_light_shadow()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xspot_light_shadow<D>::set_defaults()
    {
        this->_model_name() = "SpotLightShadowModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xspot_light_shadow));
//}
#endif