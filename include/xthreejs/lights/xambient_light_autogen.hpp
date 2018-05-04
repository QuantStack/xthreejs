#ifndef XTHREE_AMBIENT_LIGHT_HPP
#define XTHREE_AMBIENT_LIGHT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xlight_autogen.hpp"

namespace xthree
{
    //
    // ambient_light declaration
    //

    template<class D>
    class xambient_light : public xlight<D>
    {
    public:

        using base_type = xlight<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xambient_light();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using ambient_light = xw::xmaterialize<xambient_light>;

    using ambient_light_generator = xw::xgenerator<xambient_light>;

    //
    // ambient_light implementation
    //


    template <class D>
    inline void xambient_light<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xambient_light<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xambient_light<D>::xambient_light()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xambient_light<D>::set_defaults()
    {
        this->_model_name() = "AmbientLightModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xambient_light));
//}
#endif