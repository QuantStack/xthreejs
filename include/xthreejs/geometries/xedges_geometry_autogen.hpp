#ifndef XTHREE_EDGES_GEOMETRY_HPP
#define XTHREE_EDGES_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"
#include "xwidgets/xprecompiled_macros.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"

namespace xthree
{
    //
    // edges_geometry declaration
    //

    template<class D>
    class xedges_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);


    protected:

        xedges_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using edges_geometry = xw::xmaterialize<xedges_geometry>;

    using edges_geometry_generator = xw::xgenerator<xedges_geometry>;

    //
    // edges_geometry implementation
    //

    template <class D>
    inline void xedges_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xedges_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xedges_geometry<D>::xedges_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xedges_geometry<D>::set_defaults()
    {
        this->_model_name() = "EdgesGeometryModel";
        this->_view_name() = "";
    }
}

//namespace xw
//{
//    XPRECOMPILE(EXTERN, (xthree::xedges_geometry));
//}
#endif