#ifndef XTHREE_FOG_HPP
#define XTHREE_FOG_HPP

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
    // fog declaration
    //

    template<class D>
    class xfog : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(std::string, derived_type, name, "");
        XPROPERTY(xw::html_color, derived_type, color, "white");
        XPROPERTY(double, derived_type, near, 1);
        XPROPERTY(double, derived_type, far, 1000);


        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xfog();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using fog = xw::xmaterialize<xfog>;

    using fog_generator = xw::xgenerator<xfog>;

    //
    // fog implementation
    //


    template <class D>
    inline void xfog<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(name, state, buffers);
        xw::set_patch_from_property(color, state, buffers);
        xw::set_patch_from_property(near, state, buffers);
        xw::set_patch_from_property(far, state, buffers);
    }

    template <class D>
    inline void xfog<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(name, patch, buffers);
        xw::set_property_from_patch(color, patch, buffers);
        xw::set_property_from_patch(near, patch, buffers);
        xw::set_property_from_patch(far, patch, buffers);
    }

    template <class D>
    inline xfog<D>::xfog()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xfog<D>::set_defaults()
    {
        this->_model_name() = "FogModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xfog>& widget)
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
        extern template class xw::xmaterialize<xthree::xfog>;
        extern template xw::xmaterialize<xthree::xfog>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xfog>>;
        extern template class xw::xgenerator<xthree::xfog>;
        extern template xw::xgenerator<xthree::xfog>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xfog>>;
    #endif
#endif

#endif