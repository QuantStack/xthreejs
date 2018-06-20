#ifndef XTHREE_LINE_HPP
#define XTHREE_LINE_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../core/xobject3d.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // line declaration
    //

    template<class D>
    class xline : public xobject3d<D>
    {
    public:

        using base_type = xobject3d<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, material);
        XPROPERTY(xtl::xoptional<xw::xholder<xthree_widget>>, derived_type, geometry);
        XPROPERTY(std::string, derived_type, type, "Line");


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xline();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using line = xw::xmaterialize<xline>;

    using line_generator = xw::xgenerator<xline>;

    //
    // line implementation
    //


    template <class D>
    inline void xline<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(material, state, buffers);
        xw::set_patch_from_property(geometry, state, buffers);
        xw::set_patch_from_property(type, state, buffers);
    }

    template <class D>
    inline void xline<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(material, patch, buffers);
        xw::set_property_from_patch(geometry, patch, buffers);
        xw::set_property_from_patch(type, patch, buffers);
    }

    template <class D>
    inline xline<D>::xline()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xline<D>::set_defaults()
    {
        this->_model_name() = "LineModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xline>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xline>;
        extern template xw::xmaterialize<xthree::xline>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xline>>;
        extern template class xw::xgenerator<xthree::xline>;
        extern template xw::xgenerator<xthree::xline>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xline>>;
    #endif
#endif

#endif