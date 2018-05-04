#ifndef XTHREE_DIRECT_GEOMETRY_HPP
#define XTHREE_DIRECT_GEOMETRY_HPP

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
    // direct_geometry declaration
    //

    template<class D>
    class xdirect_geometry : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xdirect_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using direct_geometry = xw::xmaterialize<xdirect_geometry>;

    using direct_geometry_generator = xw::xgenerator<xdirect_geometry>;

    //
    // direct_geometry implementation
    //


    template <class D>
    inline void xdirect_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xdirect_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xdirect_geometry<D>::xdirect_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xdirect_geometry<D>::set_defaults()
    {
        this->_model_name() = "DirectGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xdirect_geometry));
//}
#endif