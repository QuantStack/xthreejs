#ifndef XTHREE_TRIANGLE_HPP
#define XTHREE_TRIANGLE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "xtensor/xtensor.hpp"
#include "xtensor/xadapt.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"

namespace xthree
{
    //
    // triangle declaration
    //

    template<class D>
    class xtriangle : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(vector3, derived_type, a, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, b, vector3({0,0,0}));
        XPROPERTY(vector3, derived_type, c, vector3({0,0,0}));


    protected:

        xtriangle();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using triangle = xw::xmaterialize<xtriangle>;

    using triangle_generator = xw::xgenerator<xtriangle>;

    //
    // triangle implementation
    //


    template <class D>
    inline void xtriangle<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(a, state, buffers);
        xw::set_patch_from_property(b, state, buffers);
        xw::set_patch_from_property(c, state, buffers);
    }

    template <class D>
    inline void xtriangle<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(a, patch, buffers);
        xw::set_property_from_patch(b, patch, buffers);
        xw::set_property_from_patch(c, patch, buffers);
    }

    template <class D>
    inline xtriangle<D>::xtriangle()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xtriangle<D>::set_defaults()
    {
        this->_model_name() = "TriangleModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xtriangle));
//}
#endif