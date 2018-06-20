#ifndef XTHREE_BUFFER_ATTRIBUTE_BASE_HPP
#define XTHREE_BUFFER_ATTRIBUTE_BASE_HPP

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
    // buffer_attribute_base declaration
    //

    template<class D>
    class xbuffer_attribute_base : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);

        XPROPERTY(webgldataunion<float>, derived_type, array);
        XPROPERTY(bool, derived_type, dynamic, false);
        XPROPERTY(bool, derived_type, needsUpdate, false);
        XPROPERTY(bool, derived_type, normalized, true);
        XPROPERTY(int, derived_type, version, -1);

        const std::vector<xw::xjson_path_type>& buffer_paths() const;

        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xbuffer_attribute_base();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using buffer_attribute_base = xw::xmaterialize<xbuffer_attribute_base>;

    using buffer_attribute_base_generator = xw::xgenerator<xbuffer_attribute_base>;

    //
    // buffer_attribute_base implementation
    //

    template <class D>
    inline const std::vector<xw::xjson_path_type>&  xbuffer_attribute_base<D>::buffer_paths() const
    {
        static const std::vector<xw::xjson_path_type> default_buffer_paths = { 
            { "array", "buffer" },
        };
        return default_buffer_paths;
    }

    template <class D>
    inline void xbuffer_attribute_base<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

        xw::set_patch_from_property(array, state, buffers);
        xw::set_patch_from_property(dynamic, state, buffers);
        xw::set_patch_from_property(needsUpdate, state, buffers);
        xw::set_patch_from_property(normalized, state, buffers);
        xw::set_patch_from_property(version, state, buffers);
    }

    template <class D>
    inline void xbuffer_attribute_base<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

        xw::set_property_from_patch(array, patch, buffers);
        xw::set_property_from_patch(dynamic, patch, buffers);
        xw::set_property_from_patch(needsUpdate, patch, buffers);
        xw::set_property_from_patch(normalized, patch, buffers);
        xw::set_property_from_patch(version, patch, buffers);
    }

    template <class D>
    inline xbuffer_attribute_base<D>::xbuffer_attribute_base()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xbuffer_attribute_base<D>::set_defaults()
    {
        this->_model_name() = "BufferAttributeBaseModel";
        this->_view_name() = "";
    }
}


/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xbuffer_attribute_base>;
        extern template xw::xmaterialize<xthree::xbuffer_attribute_base>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xbuffer_attribute_base>>;
        extern template class xw::xgenerator<xthree::xbuffer_attribute_base>;
        extern template xw::xgenerator<xthree::xbuffer_attribute_base>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xbuffer_attribute_base>>;
    #endif
#endif

#endif