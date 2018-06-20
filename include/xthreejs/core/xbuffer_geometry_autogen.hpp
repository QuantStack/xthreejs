#ifndef XTHREE_BUFFER_GEOMETRY_HPP
#define XTHREE_BUFFER_GEOMETRY_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "xbase_buffer_geometry_autogen.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // buffer_geometry declaration
    //

    template<class D>
    class xbuffer_geometry : public xbase_buffer_geometry<D>
    {
    public:

        using base_type = xbase_buffer_geometry<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, index);
        XPROPERTY(dict, derived_type, attributes, {});
        
        XPROPERTY(int, derived_type, MaxIndex, 65535);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, _ref_geometry);
        XPROPERTY(bool, derived_type, _store_ref, false);
        XPROPERTY(std::string, derived_type, type, "BufferGeometry");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xbuffer_geometry();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using buffer_geometry = xw::xmaterialize<xbuffer_geometry>;

    using buffer_geometry_generator = xw::xgenerator<xbuffer_geometry>;

    //
    // buffer_geometry implementation
    //


    template <class D>
    inline void xbuffer_geometry<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(index, state, buffers);
        xw::set_patch_from_property(attributes, state, buffers);
        xw::set_patch_from_property(MaxIndex, state, buffers);
        xw::set_patch_from_property(_ref_geometry, state, buffers);
        xw::set_patch_from_property(_store_ref, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xbuffer_geometry<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(index, patch, buffers);
        xw::set_property_from_patch(attributes, patch, buffers);
        xw::set_property_from_patch(MaxIndex, patch, buffers);
        xw::set_property_from_patch(_ref_geometry, patch, buffers);
        xw::set_property_from_patch(_store_ref, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xbuffer_geometry<D>::xbuffer_geometry()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbuffer_geometry<D>::set_defaults()
    {
        this->_model_name() = "BufferGeometryModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xbuffer_geometry>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xbuffer_geometry>;
        extern template xw::xmaterialize<xthree::xbuffer_geometry>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_geometry>>;
        extern template class xw::xgenerator<xthree::xbuffer_geometry>;
        extern template xw::xgenerator<xthree::xbuffer_geometry>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xbuffer_geometry>>;
    #endif
#endif

#endif