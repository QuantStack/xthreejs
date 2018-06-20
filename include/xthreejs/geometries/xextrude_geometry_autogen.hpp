#ifndef XTHREE_EXTRUDE_GEOMETRY_HPP
#define XTHREE_EXTRUDE_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xbase_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // extrude_geometry declaration
    //

    template<class D>
    class xextrude_geometry : public xbase_geometry<D>
    {
    public:

        using base_type = xbase_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, type, "ExtrudeGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xextrude_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using extrude_geometry = xw::xmaterialize<xextrude_geometry>;

    using extrude_geometry_generator = xw::xgenerator<xextrude_geometry>;

    //
    // extrude_geometry implementation
    //


    template <class D>
    inline void xextrude_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xextrude_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xextrude_geometry<D>::xextrude_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xextrude_geometry<D>::set_defaults()
    {
        this->_model_name() = "ExtrudeGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xextrude_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xextrude_geometry>;
        extern template xw::xmaterialize<xthree::xextrude_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xextrude_geometry>>;
        extern template class xw::xgenerator<xthree::xextrude_geometry>;
        extern template xw::xgenerator<xthree::xextrude_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xextrude_geometry>>;
    #endif
#endif

#endif