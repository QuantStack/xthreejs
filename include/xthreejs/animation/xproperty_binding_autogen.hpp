#ifndef XTHREE_PROPERTY_BINDING_HPP
#define XTHREE_PROPERTY_BINDING_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // property_binding declaration
    //

    template<class D>
    class xproperty_binding : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xproperty_binding();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using property_binding = xw::xmaterialize<xproperty_binding>;

    using property_binding_generator = xw::xgenerator<xproperty_binding>;

    //
    // property_binding implementation
    //


    template <class D>
    inline void xproperty_binding<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xproperty_binding<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xproperty_binding<D>::xproperty_binding()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xproperty_binding<D>::set_defaults()
    {
        this->_model_name() = "PropertyBindingModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xproperty_binding>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xproperty_binding>;
        extern template xw::xmaterialize<xthree::xproperty_binding>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xproperty_binding>>;
        extern template class xw::xgenerator<xthree::xproperty_binding>;
        extern template xw::xgenerator<xthree::xproperty_binding>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xproperty_binding>>;
    #endif
#endif

#endif