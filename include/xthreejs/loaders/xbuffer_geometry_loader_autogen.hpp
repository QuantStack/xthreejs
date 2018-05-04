#ifndef XTHREE_BUFFER_GEOMETRY_LOADER_HPP
#define XTHREE_BUFFER_GEOMETRY_LOADER_HPP

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
    // buffer_geometry_loader declaration
    //

    template<class D>
    class xbuffer_geometry_loader : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;
        using buffer_type = xt::xtensor<float, 2>;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



    protected:

        xbuffer_geometry_loader();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using buffer_geometry_loader = xw::xmaterialize<xbuffer_geometry_loader>;

    using buffer_geometry_loader_generator = xw::xgenerator<xbuffer_geometry_loader>;

    //
    // buffer_geometry_loader implementation
    //


    template <class D>
    inline void xbuffer_geometry_loader<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xbuffer_geometry_loader<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xbuffer_geometry_loader<D>::xbuffer_geometry_loader()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbuffer_geometry_loader<D>::set_defaults()
    {
        this->_model_name() = "BufferGeometryLoaderModel";
        this->_view_name() = "";
    }
}

/*********************
 * precompiled types *
 *********************/

#ifndef _WIN32
    extern template class xw::xmaterialize<xthree::xbuffer_geometry_loader>;
    extern template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_geometry_loader>>;
    extern template class xw::xgenerator<xthree::xbuffer_geometry_loader>;
    extern template class xw::xtransport<xw::xgenerator<xthree::xbuffer_geometry_loader>>;
#endif

#endif